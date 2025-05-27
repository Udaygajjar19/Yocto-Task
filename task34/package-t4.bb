SUMMARY = "Utility to calculate total size of all regular files in a directory"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "file://total_file_size.c \
	   file://total_file_size.1 \
	   "

S = "${WORKDIR}/sources-unpack"

do_compile() {
    gcc total_file_size.c -o total_file_size
}

do_install() {

    install -d ${D}${bindir}
    install -m 0755 total_file_size ${D}${bindir}/total_file_size

    install -d ${D}${mandir}/man1
    install -m 0644 total_file_size.1 ${D}${mandir}/man1/total_file_size.1
}
FILES_${PN}-doc = "/usr/share/man"
