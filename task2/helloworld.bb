DESCRIPTION = "Simple Hello World application"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRCREV = "${AUTOREV}"
SRC_URI = "file://src/ "
S="${WORKDIR}/src"
#HOST_CC="gcc "
#CC="${HOST_CC}"

do_compile() {
   gcc helloworld.c -o helloworld
}

do_install() {
    install -d ${D}${bindir}
    install -m 0777 helloworld ${D}${bindir}/helloworld
}

