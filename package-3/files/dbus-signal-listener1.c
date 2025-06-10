#include <dbus/dbus-glib-lowlevel.h>
#include <glib.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/* Prototype declaration */
static DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *message, void *user_data);
static DBusHandlerResult method_handler(DBusConnection *connection, DBusMessage *message, void *user_data);

/* Main function */
int main(int argc, char **argv)
{
        GMainLoop *loop;
        DBusConnection *bus;
        DBusError error;

        /* Create a new GLib event loop */
        loop = g_main_loop_new(NULL, FALSE);

        /* Initialize D-Bus error handling */
        dbus_error_init(&error);

        /* ✅ Connect to the session bus */
/*        bus = dbus_bus_get(DBUS_BUS_SESSION, &error);
        if (!bus)
        {
                g_warning("Failed to connect to the D-BUS daemon: %s", error.message);
                dbus_error_free(&error);
                return 1;
        }*/
	/* Connect to the session bus */
	bus = dbus_bus_get(DBUS_BUS_SESSION, &error);
	if (!bus)
	{
    		g_warning("Failed to connect to the D-BUS daemon: %s", error.message);
    		dbus_error_free(&error);
    		return 1;
	}

	/* Request a well-known name so others can call this service */
	dbus_bus_request_name(bus, "aditya.volumeclient", DBUS_NAME_FLAG_REPLACE_EXISTING, &error);
	if (dbus_error_is_set(&error))
	{
    		g_warning("Failed to acquire service name: %s", error.message);
    		dbus_error_free(&error);
    		return 1;
	}


        /* ✅ Set up D-Bus to work with the GLib main loop */
        dbus_connection_setup_with_g_main(bus, NULL);

        /* ✅ Register object path for method calls (after connection is valid) */
        if (!dbus_connection_register_object_path(bus, "/aditya/volumeobject",
            &(DBusObjectPathVTable){.message_function = method_handler}, NULL))
        {
                g_warning("Failed to register object path for volume interface");
                return 1;
        }

        /* Listen for messages from all objects with the given interface */
        dbus_bus_add_match(bus, "type='signal',interface='aditya.interface1'", &error);
        if (dbus_error_is_set(&error))
        {
                g_warning("Failed to add D-Bus match: %s", error.message);
                dbus_error_free(&error);
                return 1;
        }

        /* Add a filter function to handle received signals */
        dbus_connection_add_filter(bus, signal_filter, loop, NULL);

        /* Start the GLib event loop */
        g_main_loop_run(loop);
        return 0;
}

static DBusHandlerResult method_handler(DBusConnection *connection, DBusMessage *message, void *user_data)
{
/*	if (dbus_message_is_method_call(message, "aditya.volumeinterface", "SetVolume"))
	{
		DBusMessage *reply;
		DBusMessageIter args;
		DBusMessageIter reply_args;
		dbus_int32_t volume_level;

		// Read the method argument (int32)
		if (!dbus_message_iter_init(message, &args))
		{
			g_warning("Message has no arguments!");
			return DBUS_HANDLER_RESULT_HANDLED;
		}

		if (DBUS_TYPE_INT32 != dbus_message_iter_get_arg_type(&args))
		{
			g_warning("Argument is not int32!");
			return DBUS_HANDLER_RESULT_HANDLED;
		}

		dbus_message_iter_get_basic(&args, &volume_level);
		g_print("SetVolume called with level: %d\n", volume_level);

		// Simulate setting volume
		// You could add actual volume control using ALSA or pactl here
		g_print("Volume set to %d (simulated)\n", volume_level);

		// Create a reply message
		reply = dbus_message_new_method_return(message);

		// Add return value to the reply
		dbus_message_iter_init_append(reply, &reply_args);
		dbus_int32_t success = 1;
		dbus_message_iter_append_basic(&reply_args, DBUS_TYPE_INT32, &success);

		// Send reply
		dbus_connection_send(connection, reply, NULL);
		dbus_connection_flush(connection);
		dbus_message_unref(reply);

		return DBUS_HANDLER_RESULT_HANDLED;
	}

	return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;*/
	if (dbus_message_is_method_call(message, "aditya.volumeinterface", "SetVolume"))
{
    DBusMessage *reply;
    DBusMessageIter args;
    DBusMessageIter reply_args;
    dbus_int32_t volume_level;

    if (!dbus_message_iter_init(message, &args))
    {
        g_warning("Message has no arguments!");
        return DBUS_HANDLER_RESULT_HANDLED;
    }

    if (DBUS_TYPE_INT32 != dbus_message_iter_get_arg_type(&args))
    {
        g_warning("Argument is not int32!");
        return DBUS_HANDLER_RESULT_HANDLED;
    }

    dbus_message_iter_get_basic(&args, &volume_level);
    g_print("SetVolume called with level: %d\n", volume_level);

    // 🔊 Set volume using pactl
    char command[128];
    snprintf(command, sizeof(command), "pactl set-sink-volume @DEFAULT_SINK@ %d%%", volume_level);
    int result = system(command);
    g_print("Volume set using pactl: result = %d\n", result);

    // Send reply back
    reply = dbus_message_new_method_return(message);
    dbus_message_iter_init_append(reply, &reply_args);
    dbus_int32_t success = 1;
    dbus_message_iter_append_basic(&reply_args, DBUS_TYPE_INT32, &success);
    dbus_connection_send(connection, reply, NULL);
    dbus_connection_flush(connection);
    dbus_message_unref(reply);

    return DBUS_HANDLER_RESULT_HANDLED;
}

}


/* Function to handle incoming D-Bus signals */
static DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *message, void *user_data)
{
	GMainLoop *loop = user_data;

	/* Handle disconnection signal */
	if (dbus_message_is_signal(message, DBUS_INTERFACE_LOCAL, "Disconnected"))
	{
		g_main_loop_quit(loop);
		return DBUS_HANDLER_RESULT_HANDLED;
	}

	/* Handle "Ping" signal with a string message */
	if (dbus_message_is_signal(message, "aditya.interface1", "Ping"))
	{
		DBusError error;
		char *received_msg = NULL;

		dbus_error_init(&error);
		if (dbus_message_get_args(message, &error, DBUS_TYPE_STRING, &received_msg, DBUS_TYPE_INVALID))
		{
			if (!received_msg)
			{
				g_warning("Received NULL message.");
				return DBUS_HANDLER_RESULT_HANDLED;
			}

			/* Make a safe copy of the received message */
			char *safe_msg = g_strdup(received_msg);
			if (!safe_msg)
			{
				g_warning("Memory allocation failed.");
				return DBUS_HANDLER_RESULT_HANDLED;
			}

			g_print("Received message: %s\n", safe_msg);

			/* Check if the message is a command */
			if (g_str_has_prefix(safe_msg, "cmd:"))
			{
				const char *command = safe_msg + 4; /* Skip "cmd:" prefix */
				g_print("Executing command: %s\n", command);

				/* Execute the command */
				int result = system(command);
				g_print("Command executed with result: %d\n", result);
			}

			/* Free the allocated safe copy */
			g_free(safe_msg);
		}
		else
		{
			g_warning("Error receiving message: %s\n", error.message);
			dbus_error_free(&error);
		}

		return DBUS_HANDLER_RESULT_HANDLED;
	}

	return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

