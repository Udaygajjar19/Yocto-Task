DESCRIPTION = "Recipe for changing the library path,applying patch for fixing install path and adding patch for adding the licence details in header"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRCREV = "${AUTOREV}"
SRC_URI = "file://source/ "
S="${WORKDIR}/source"

do_compile() {
   ${CC} ${INCFLAG} ${LDFLAGS} libchange.c -o libchange
}

do_install() {
    install -d ${D}${bindir}
}

