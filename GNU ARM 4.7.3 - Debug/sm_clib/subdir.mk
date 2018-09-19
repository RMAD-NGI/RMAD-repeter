################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sm_clib/dn_endianness.c \
../sm_clib/dn_hdlc.c \
../sm_clib/dn_ipmg.c \
../sm_clib/dn_ipmt.c \
../sm_clib/dn_lock.c \
../sm_clib/dn_serial_mg.c \
../sm_clib/dn_serial_mt.c \
../sm_clib/dn_uart.c \
../sm_clib/dn_whmt.c 

OBJS += \
./sm_clib/dn_endianness.o \
./sm_clib/dn_hdlc.o \
./sm_clib/dn_ipmg.o \
./sm_clib/dn_ipmt.o \
./sm_clib/dn_lock.o \
./sm_clib/dn_serial_mg.o \
./sm_clib/dn_serial_mt.o \
./sm_clib/dn_uart.o \
./sm_clib/dn_whmt.o 

C_DEPS += \
./sm_clib/dn_endianness.d \
./sm_clib/dn_hdlc.d \
./sm_clib/dn_ipmg.d \
./sm_clib/dn_ipmt.d \
./sm_clib/dn_lock.d \
./sm_clib/dn_serial_mg.d \
./sm_clib/dn_serial_mt.d \
./sm_clib/dn_uart.d \
./sm_clib/dn_whmt.d 


# Each subdirectory must supply rules for building sources it contributes
sm_clib/dn_endianness.o: ../sm_clib/dn_endianness.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_endianness.d" -MT"sm_clib/dn_endianness.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_hdlc.o: ../sm_clib/dn_hdlc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_hdlc.d" -MT"sm_clib/dn_hdlc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_ipmg.o: ../sm_clib/dn_ipmg.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_ipmg.d" -MT"sm_clib/dn_ipmg.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_ipmt.o: ../sm_clib/dn_ipmt.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_ipmt.d" -MT"sm_clib/dn_ipmt.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_lock.o: ../sm_clib/dn_lock.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_lock.d" -MT"sm_clib/dn_lock.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_serial_mg.o: ../sm_clib/dn_serial_mg.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_serial_mg.d" -MT"sm_clib/dn_serial_mg.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_serial_mt.o: ../sm_clib/dn_serial_mt.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_serial_mt.d" -MT"sm_clib/dn_serial_mt.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_uart.o: ../sm_clib/dn_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_uart.d" -MT"sm_clib/dn_uart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sm_clib/dn_whmt.o: ../sm_clib/dn_whmt.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"sm_clib/dn_whmt.d" -MT"sm_clib/dn_whmt.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


