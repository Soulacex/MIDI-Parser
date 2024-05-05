################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/examples/hello_world.c \
../Core/Src/examples/midi_header.c \
../Core/Src/examples/timer.c 

OBJS += \
./Core/Src/examples/hello_world.o \
./Core/Src/examples/midi_header.o \
./Core/Src/examples/timer.o 

C_DEPS += \
./Core/Src/examples/hello_world.d \
./Core/Src/examples/midi_header.d \
./Core/Src/examples/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/examples/%.o Core/Src/examples/%.su Core/Src/examples/%.cyclo: ../Core/Src/examples/%.c Core/Src/examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw/hw_3 -I../Core/Inc/hw/hw_8/ -I../Core/Inc/hw/hw_5 -I../Core/Inc/hw -I../Core/Inc/hw/hw_1 -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/hw/hw_6 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-examples

clean-Core-2f-Src-2f-examples:
	-$(RM) ./Core/Src/examples/hello_world.cyclo ./Core/Src/examples/hello_world.d ./Core/Src/examples/hello_world.o ./Core/Src/examples/hello_world.su ./Core/Src/examples/midi_header.cyclo ./Core/Src/examples/midi_header.d ./Core/Src/examples/midi_header.o ./Core/Src/examples/midi_header.su ./Core/Src/examples/timer.cyclo ./Core/Src/examples/timer.d ./Core/Src/examples/timer.o ./Core/Src/examples/timer.su

.PHONY: clean-Core-2f-Src-2f-examples

