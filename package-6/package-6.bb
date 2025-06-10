SUMMARY = "A simple DBus application between server and client to transfer user defined messages"
DESCRIPTION = "This program connects to the DBus session bus and sends a user defined ping to the client"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRCREV = "${AUTOREV}"
SRC_URI = "file://dbus-signal-sender.c \
           file://dbus-signal-listener.c \
           file://dbus-signal-listener1.c \
           file://dbus-signal-sender1.c \
           file://dbus-signal-sender2.c \
           file://Makefile \
                "
 
BB_STRICT_CHECKSUM = "0"

DEPENDS += "dbus dbus-glib glib-2.0" 
inherit pkgconfig
S = "${WORKDIR}/sources-unpack"
 
do_configure[noexec] = "1"
 
do_compile() {
     oe_runmake
}
 
do_install() {
        install -d ${D}${bindir}
        install -m 0755 dbus-signal-sender ${D}${bindir}/
        install -m 0755 dbus-signal-listener ${D}${bindir}/
        install -m 0755 dbus-signal-listener1 ${D}${bindir}/
        install -m 0755 dbus-signal-sender1 ${D}${bindir}/
        install -m 0755 dbus-signal-sender2 ${D}${bindir}/
} 
