DESCRIPTION = "Simple DR  application"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRCREV = "${AUTOREV}"
SRC_URI = "file://src/"
S="${WORKDIR}/src"

do_compile() {
    oe_runmake
}

do_install() {
    install -d ${D}${bindir}
    install -m 0777 output ${D}${bindir}
}

