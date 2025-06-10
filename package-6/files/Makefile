
all: dbus-signal-sender dbus-signal-listener dbus-signal-listener1 dbus-signal-sender1 dbus-signal-sender2

#dbus-signal: dbus-signal.c
#	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`


CFLAGS += $(shell pkg-config --cflags dbus-1 dbus-glib-1)
LDFLAGS += $(shell pkg-config --libs dbus-1 dbus-glib-1)

dbus-signal-sender: dbus-signal-sender.c
	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`

dbus-signal-listener: dbus-signal-listener.c
	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`

dbus-signal-listener1: dbus-signal-listener1.c
	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`

dbus-signal-sender1: dbus-signal-sender1.c
	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`

dbus-signal-sender2: dbus-signal-sender2.c
	gcc -o $@ $< `pkg-config --cflags --libs dbus-1 dbus-glib-1`

clean:
	rm dbus-signal-sender dbus-signal-listener dbus-signal-listener1 dbus-signal-sender1 dbus-signal-sender2
