/* required header files */
#include <dbus/dbus-glib-lowlevel.h>
#include <glib.h>
#include <dbus/dbus-glib.h>
#include <dbus/dbus.h>

/* prototype decleration of function */
static DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *message1, void *user_data);

/* start of main function */
int main(int argc, char **argv) 
{
    	GMainLoop *loop;
    	DBusConnection *bus;
    	DBusError error;

    	/* Create a new GLib event loop */
    	loop = g_main_loop_new(NULL, FALSE);

    	/* Initialize D-Bus error handling */
    	dbus_error_init(&error);

    	/* Connect to the session bus */
    	bus = dbus_bus_get(DBUS_BUS_SESSION, &error);
    	if (!bus) 
	{
        	g_warning("Failed to connect to the D-BUS daemon: %s", error.message);
        	dbus_error_free(&error);
        	return 1;
    	}

    	/* Set up D-Bus to work with the GLib main loop */
    	dbus_connection_setup_with_g_main(bus, NULL);

    	/* Listen to messages from all objects with the given interface */
    	dbus_bus_add_match(bus, "type='signal',interface='com.burtonini.dbus.Signal1'", &error);
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
/* end of main function */


/* start of Function to handle incoming D-Bus signals */
static DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *message1, void *user_data) 
{
    	GMainLoop *loop = user_data;

    	/* Handle disconnection signal */
    	if (dbus_message_is_signal(message1, DBUS_INTERFACE_LOCAL, "Disconnected")) 
	{
        	g_main_loop_quit(loop);
        	return DBUS_HANDLER_RESULT_HANDLED;
    	}

    	/* Handle "Ping" signal with a string message */
    	if (dbus_message_is_signal(message1, "com.burtonini.dbus.Signal1", "Ping")) 
	{
        	DBusError error;
        	char *received_msg;

        	dbus_error_init(&error);
        	if (dbus_message_get_args(message1, &error, DBUS_TYPE_STRING, &received_msg, DBUS_TYPE_INVALID)) 
		{
            		g_print("Received message: %s\n", received_msg);
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
/* end of function to receive string */
