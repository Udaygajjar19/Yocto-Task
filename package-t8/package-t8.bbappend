INCFLAG = "-Iinclude/"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 libchange ${D}${bindir}
}
