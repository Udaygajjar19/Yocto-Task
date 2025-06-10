DESCRIPTION = "Recipe for Dennis Ritchiee and YPK module which will create the executable file of DR and YPK using makefile"
SECTION = "DR"
LICENSE = "CLOSED"

SRC_URI = "file://sources/ "

S = "${WORKDIR}/sources"

inherit rm_work


do_compile(){
	oe_runmake
}

do_install(){
	install -d ${D}${bindir}
	install -m 0755 dr-files/bin/main ${D}${bindir}/dr-all
}
