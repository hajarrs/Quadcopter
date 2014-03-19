#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=my_new_pid.s CB_Inicializaciones.c CB_Timer1.c CB_Timer2.c CB_Timer3.c CB_Timer5.c Pruebas.c main.c CA_funciones_control.c CA_SetGetMPU6050.c CB_Bluetooth.c CB_I2C.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/my_new_pid.o ${OBJECTDIR}/CB_Inicializaciones.o ${OBJECTDIR}/CB_Timer1.o ${OBJECTDIR}/CB_Timer2.o ${OBJECTDIR}/CB_Timer3.o ${OBJECTDIR}/CB_Timer5.o ${OBJECTDIR}/Pruebas.o ${OBJECTDIR}/main.o ${OBJECTDIR}/CA_funciones_control.o ${OBJECTDIR}/CA_SetGetMPU6050.o ${OBJECTDIR}/CB_Bluetooth.o ${OBJECTDIR}/CB_I2C.o
POSSIBLE_DEPFILES=${OBJECTDIR}/my_new_pid.o.d ${OBJECTDIR}/CB_Inicializaciones.o.d ${OBJECTDIR}/CB_Timer1.o.d ${OBJECTDIR}/CB_Timer2.o.d ${OBJECTDIR}/CB_Timer3.o.d ${OBJECTDIR}/CB_Timer5.o.d ${OBJECTDIR}/Pruebas.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/CA_funciones_control.o.d ${OBJECTDIR}/CA_SetGetMPU6050.o.d ${OBJECTDIR}/CB_Bluetooth.o.d ${OBJECTDIR}/CB_I2C.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/my_new_pid.o ${OBJECTDIR}/CB_Inicializaciones.o ${OBJECTDIR}/CB_Timer1.o ${OBJECTDIR}/CB_Timer2.o ${OBJECTDIR}/CB_Timer3.o ${OBJECTDIR}/CB_Timer5.o ${OBJECTDIR}/Pruebas.o ${OBJECTDIR}/main.o ${OBJECTDIR}/CA_funciones_control.o ${OBJECTDIR}/CA_SetGetMPU6050.o ${OBJECTDIR}/CB_Bluetooth.o ${OBJECTDIR}/CB_I2C.o

# Source Files
SOURCEFILES=my_new_pid.s CB_Inicializaciones.c CB_Timer1.c CB_Timer2.c CB_Timer3.c CB_Timer5.c Pruebas.c main.c CA_funciones_control.c CA_SetGetMPU6050.c CB_Bluetooth.c CB_I2C.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4013
MP_LINKER_FILE_OPTION=,--script=p30F4013.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/CB_Inicializaciones.o: CB_Inicializaciones.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Inicializaciones.o.d 
	@${RM} ${OBJECTDIR}/CB_Inicializaciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Inicializaciones.c  -o ${OBJECTDIR}/CB_Inicializaciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Inicializaciones.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Inicializaciones.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer1.o: CB_Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer1.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer1.c  -o ${OBJECTDIR}/CB_Timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer2.o: CB_Timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer2.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer2.c  -o ${OBJECTDIR}/CB_Timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer3.o: CB_Timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer3.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer3.c  -o ${OBJECTDIR}/CB_Timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer5.o: CB_Timer5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer5.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer5.c  -o ${OBJECTDIR}/CB_Timer5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer5.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Pruebas.o: Pruebas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Pruebas.o.d 
	@${RM} ${OBJECTDIR}/Pruebas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Pruebas.c  -o ${OBJECTDIR}/Pruebas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Pruebas.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Pruebas.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CA_funciones_control.o: CA_funciones_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CA_funciones_control.o.d 
	@${RM} ${OBJECTDIR}/CA_funciones_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CA_funciones_control.c  -o ${OBJECTDIR}/CA_funciones_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CA_funciones_control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CA_funciones_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CA_SetGetMPU6050.o: CA_SetGetMPU6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CA_SetGetMPU6050.o.d 
	@${RM} ${OBJECTDIR}/CA_SetGetMPU6050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CA_SetGetMPU6050.c  -o ${OBJECTDIR}/CA_SetGetMPU6050.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CA_SetGetMPU6050.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CA_SetGetMPU6050.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Bluetooth.o: CB_Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Bluetooth.o.d 
	@${RM} ${OBJECTDIR}/CB_Bluetooth.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Bluetooth.c  -o ${OBJECTDIR}/CB_Bluetooth.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Bluetooth.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Bluetooth.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_I2C.o: CB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_I2C.o.d 
	@${RM} ${OBJECTDIR}/CB_I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_I2C.c  -o ${OBJECTDIR}/CB_I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_I2C.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/CB_Inicializaciones.o: CB_Inicializaciones.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Inicializaciones.o.d 
	@${RM} ${OBJECTDIR}/CB_Inicializaciones.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Inicializaciones.c  -o ${OBJECTDIR}/CB_Inicializaciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Inicializaciones.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Inicializaciones.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer1.o: CB_Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer1.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer1.c  -o ${OBJECTDIR}/CB_Timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer1.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer2.o: CB_Timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer2.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer2.c  -o ${OBJECTDIR}/CB_Timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer2.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer3.o: CB_Timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer3.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer3.c  -o ${OBJECTDIR}/CB_Timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer3.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Timer5.o: CB_Timer5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Timer5.o.d 
	@${RM} ${OBJECTDIR}/CB_Timer5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Timer5.c  -o ${OBJECTDIR}/CB_Timer5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Timer5.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Timer5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Pruebas.o: Pruebas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Pruebas.o.d 
	@${RM} ${OBJECTDIR}/Pruebas.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Pruebas.c  -o ${OBJECTDIR}/Pruebas.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Pruebas.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/Pruebas.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CA_funciones_control.o: CA_funciones_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CA_funciones_control.o.d 
	@${RM} ${OBJECTDIR}/CA_funciones_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CA_funciones_control.c  -o ${OBJECTDIR}/CA_funciones_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CA_funciones_control.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CA_funciones_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CA_SetGetMPU6050.o: CA_SetGetMPU6050.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CA_SetGetMPU6050.o.d 
	@${RM} ${OBJECTDIR}/CA_SetGetMPU6050.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CA_SetGetMPU6050.c  -o ${OBJECTDIR}/CA_SetGetMPU6050.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CA_SetGetMPU6050.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CA_SetGetMPU6050.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_Bluetooth.o: CB_Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_Bluetooth.o.d 
	@${RM} ${OBJECTDIR}/CB_Bluetooth.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_Bluetooth.c  -o ${OBJECTDIR}/CB_Bluetooth.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_Bluetooth.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_Bluetooth.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/CB_I2C.o: CB_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CB_I2C.o.d 
	@${RM} ${OBJECTDIR}/CB_I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  CB_I2C.c  -o ${OBJECTDIR}/CB_I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CB_I2C.o.d"      -g -omf=coff -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/CB_I2C.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/my_new_pid.o: my_new_pid.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/my_new_pid.o.d 
	@${RM} ${OBJECTDIR}/my_new_pid.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  my_new_pid.s  -o ${OBJECTDIR}/my_new_pid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff -Wa,-MD,"${OBJECTDIR}/my_new_pid.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,-g,--relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/my_new_pid.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/my_new_pid.o: my_new_pid.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/my_new_pid.o.d 
	@${RM} ${OBJECTDIR}/my_new_pid.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  my_new_pid.s  -o ${OBJECTDIR}/my_new_pid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=coff -Wa,-MD,"${OBJECTDIR}/my_new_pid.o.d",--defsym=__MPLAB_BUILD=1,-g,--relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/my_new_pid.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=coff  -mreserve=data@0x800:0x84E   -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Quadcopter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
