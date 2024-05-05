################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/hw/hw_3/midi_converter_display.c \
../Core/Src/hw/hw_3/uint16_converter.c \
../Core/Src/hw/hw_3/uint24_converter.c \
../Core/Src/hw/hw_3/uint32_converter.c 

OBJS += \
./Core/Src/hw/hw_3/midi_converter_display.o \
./Core/Src/hw/hw_3/uint16_converter.o \
./Core/Src/hw/hw_3/uint24_converter.o \
./Core/Src/hw/hw_3/uint32_converter.o 

C_DEPS += \
./Core/Src/hw/hw_3/midi_converter_display.d \
./Core/Src/hw/hw_3/uint16_converter.d \
./Core/Src/hw/hw_3/uint24_converter.d \
./Core/Src/hw/hw_3/uint32_converter.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/hw/hw_3/%.o Core/Src/hw/hw_3/%.su Core/Src/hw/hw_3/%.cyclo: ../Core/Src/hw/hw_3/%.c Core/Src/hw/hw_3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw/hw_3 -I../Core/Inc/hw/hw_8/ -I../Core/Inc/hw/hw_5 -I../Core/Inc/hw -I../Core/Inc/hw/hw_1 -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/hw/hw_6 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-hw-2f-hw_3

clean-Core-2f-Src-2f-hw-2f-hw_3:
	-$(RM) ./Core/Src/hw/hw_3/midi_converter_display.cyclo ./Core/Src/hw/hw_3/midi_converter_display.d ./Core/Src/hw/hw_3/midi_converter_display.o ./Core/Src/hw/hw_3/midi_converter_display.su ./Core/Src/hw/hw_3/uint16_converter.cyclo ./Core/Src/hw/hw_3/uint16_converter.d ./Core/Src/hw/hw_3/uint16_converter.o ./Core/Src/hw/hw_3/uint16_converter.su ./Core/Src/hw/hw_3/uint24_converter.cyclo ./Core/Src/hw/hw_3/uint24_converter.d ./Core/Src/hw/hw_3/uint24_converter.o ./Core/Src/hw/hw_3/uint24_converter.su ./Core/Src/hw/hw_3/uint32_converter.cyclo ./Core/Src/hw/hw_3/uint32_converter.d ./Core/Src/hw/hw_3/uint32_converter.o ./Core/Src/hw/hw_3/uint32_converter.su

.PHONY: clean-Core-2f-Src-2f-hw-2f-hw_3

