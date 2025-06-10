DESCRIPTION = "Simple DR  application"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""
SRCREV = "${AUTOREV}"
SRC_URI = "file://src/"
S="${WORKDIR}/src"
HOST_CC="gcc "
CC="${HOST_CC}"
FLAG="-c "

do_compile() {
 		${CC} ${FLAG}  ${WORKDIR}/src/dennisR_module2_function_*.c
		${CC} ${FLAG} ${WORKDIR}/src/main.c
		${CC} *.o -o drversion2 
}

do_install() {
    install -d ${D}${bindir}
    install -m 0777 drversion2 ${D}${bindir}
}

