DESCRIPTION = "recipe from git"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://Library_Management_System.c;md5=6003f5b55662a44430958a75a5f16cae"
SRC_URI = "git://github.com/smita3199/Library-Management-System-using-Data-Structures.git;protocol=https;branch=main \
	file://fix-bug.patch \
	file://log-file.patch "
SRCREV = "4220fbc881a113d8a10e9fa015c36c31ff29329a"

S = "${WORKDIR}/git"

 
do_compile(){
	gcc  Library_Management_System.c -o libman
}

do_install() {
	install -d ${D}${bindir}
	install -m 0755 libman ${D}${bindir}/libman
}
