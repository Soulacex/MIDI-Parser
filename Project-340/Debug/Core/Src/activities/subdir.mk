################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/activities/activity10.c \
../Core/Src/activities/activity11.c \
../Core/Src/activities/activity12.c \
../Core/Src/activities/activity8.c \
../Core/Src/activities/activity_noise.c \
../Core/Src/activities/activity_wave.c 

OBJS += \
./Core/Src/activities/activity10.o \
./Core/Src/activities/activity11.o \
./Core/Src/activities/activity12.o \
./Core/Src/activities/activity8.o \
./Core/Src/activities/activity_noise.o \
./Core/Src/activities/activity_wave.o 

C_DEPS += \
./Core/Src/activities/activity10.d \
./Core/Src/activities/activity11.d \
./Core/Src/activities/activity12.d \
./Core/Src/activities/activity8.d \
./Core/Src/activities/activity_noise.d \
./Core/Src/activities/activity_wave.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/activities/%.o Core/Src/activities/%.su Core/Src/activities/%.cyclo: ../Core/Src/activities/%.c Core/Src/activities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw/hw_3 -I../Core/Inc/hw/hw_8/ -I../Core/Inc/hw/hw_5 -I../Core/Inc/hw -I../Core/Inc/hw/hw_1 -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/hw/hw_6 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-activities

clean-Core-2f-Src-2f-activities:
	-$(RM) ./Core/Src/activities/activity10.cyclo ./Core/Src/activities/activity10.d ./Core/Src/activities/activity10.o ./Core/Src/activities/activity10.su ./Core/Src/activities/activity11.cyclo ./Core/Src/activities/activity11.d ./Core/Src/activities/activity11.o ./Core/Src/activities/activity11.su ./Core/Src/activities/activity12.cyclo ./Core/Src/activities/activity12.d ./Core/Src/activities/activity12.o ./Core/Src/activities/activity12.su ./Core/Src/activities/activity8.cyclo ./Core/Src/activities/activity8.d ./Core/Src/activities/activity8.o ./Core/Src/activities/activity8.su ./Core/Src/activities/activity_noise.cyclo ./Core/Src/activities/activity_noise.d ./Core/Src/activities/activity_noise.o ./Core/Src/activities/activity_noise.su ./Core/Src/activities/activity_wave.cyclo ./Core/Src/activities/activity_wave.d ./Core/Src/activities/activity_wave.o ./Core/Src/activities/activity_wave.su

.PHONY: clean-Core-2f-Src-2f-activities

