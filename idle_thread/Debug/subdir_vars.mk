################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../idle_thread.cfg 

CMD_SRCS += \
../EK_TM4C123GXL.cmd 

C_SRCS += \
../EK_TM4C123GXL.c \
../idle_thread.c 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_MISC_DIRS += \
./configPkg/ 

C_DEPS += \
./EK_TM4C123GXL.d \
./idle_thread.d 

GEN_OPTS += \
./configPkg/compiler.opt 

OBJS += \
./EK_TM4C123GXL.obj \
./idle_thread.obj 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

OBJS__QUOTED += \
"EK_TM4C123GXL.obj" \
"idle_thread.obj" 

C_DEPS__QUOTED += \
"EK_TM4C123GXL.d" \
"idle_thread.d" 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

C_SRCS__QUOTED += \
"../EK_TM4C123GXL.c" \
"../idle_thread.c" 


