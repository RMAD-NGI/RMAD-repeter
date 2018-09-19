################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/aux_data.c \
../src/burtc_timer.c \
../src/config_efm32.c \
../src/dn_fsm.c \
../src/irqs.c \
../src/lcd.c \
../src/repeter.c 

OBJS += \
./src/aux_data.o \
./src/burtc_timer.o \
./src/config_efm32.o \
./src/dn_fsm.o \
./src/irqs.o \
./src/lcd.o \
./src/repeter.o 

C_DEPS += \
./src/aux_data.d \
./src/burtc_timer.d \
./src/config_efm32.d \
./src/dn_fsm.d \
./src/irqs.d \
./src/lcd.d \
./src/repeter.d 


# Each subdirectory must supply rules for building sources it contributes
src/aux_data.o: ../src/aux_data.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/aux_data.d" -MT"src/aux_data.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/burtc_timer.o: ../src/burtc_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/burtc_timer.d" -MT"src/burtc_timer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/config_efm32.o: ../src/config_efm32.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/config_efm32.d" -MT"src/config_efm32.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dn_fsm.o: ../src/dn_fsm.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/dn_fsm.d" -MT"src/dn_fsm.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/irqs.o: ../src/irqs.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/irqs.d" -MT"src/irqs.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lcd.o: ../src/lcd.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/lcd.d" -MT"src/lcd.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/repeter.o: ../src/repeter.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' '-DARM_MATH_CM3=' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib" -I"C:\Users\yk\SimplicityStudio\v3_workspace\RMAD repeter - smartmeshIP - hw5 - sw2\sm_clib\ports\EFM32" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"src/repeter.d" -MT"src/repeter.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


