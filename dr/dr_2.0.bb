DESCRIPTION = "Recipe for Dennis Ritchiee and YPK module which will create the executable file of DR and YPK using makefile"
SECTION = "DR"
LICENSE = "CLOSED"

SRC_URI = "file://sources/ "

S = "${WORKDIR}/sources"


ROOT = "dr-files"
OBJFLAG = " -c"
DEBUGFLAG = " -g" 
LINKFLAG = " -lm"
INCFLAG = " -I${ROOT}/include"

do_compile(){
	${CC} ${INCFLAG} ${OBJFLAG} main.c
	${CC} ${INCFLAG} ${OBJFLAG} ${ROOT}/src/166535_*/*.c
	${CC} ${INCFLAG} ${DEBUGFLAG} ${LDFLAGS} *.o -o withoutmakefile ${LINKFLAG}
	mv *.o ${ROOT}/obj/
	cp withoutmakefile ${ROOT}/bin/
}

do_install(){
	install -d ${D}${bindir}
	install -m 0755 dr-files/bin/withoutmakefile ${D}${bindir}/withoutmakefile
}
