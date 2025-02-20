################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DHT11_Lib/CLCD_I2C.c \
../DHT11_Lib/dht11_lib.c 

OBJS += \
./DHT11_Lib/CLCD_I2C.o \
./DHT11_Lib/dht11_lib.o 

C_DEPS += \
./DHT11_Lib/CLCD_I2C.d \
./DHT11_Lib/dht11_lib.d 


# Each subdirectory must supply rules for building sources it contributes
DHT11_Lib/%.o DHT11_Lib/%.su DHT11_Lib/%.cyclo: ../DHT11_Lib/%.c DHT11_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/user/STM32CubeIDE/workspace_1.16.1/DHT11_3/DHT11_Lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DHT11_Lib

clean-DHT11_Lib:
	-$(RM) ./DHT11_Lib/CLCD_I2C.cyclo ./DHT11_Lib/CLCD_I2C.d ./DHT11_Lib/CLCD_I2C.o ./DHT11_Lib/CLCD_I2C.su ./DHT11_Lib/dht11_lib.cyclo ./DHT11_Lib/dht11_lib.d ./DHT11_Lib/dht11_lib.o ./DHT11_Lib/dht11_lib.su

.PHONY: clean-DHT11_Lib

