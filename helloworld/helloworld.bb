DESCRIPTION = "Simple Hello World application"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRC_URI = "file://helloworld.c "

S = "${WORKDIR}/sources-unpack"

do_compile() {
   ${CC} ${LDFLAGS} helloworld.c -o helloworld
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 helloworld ${D}${bindir}
}

