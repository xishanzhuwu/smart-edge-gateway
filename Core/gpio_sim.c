#include <stdio.h>
#include <windows.h>

volatile unsigned int GPIOA_CRL = 0;
volatile unsigned int GPIOA_CRH = 0;
volatile unsigned int GPIOA_IDR = 0;
volatile unsigned int GPIOA_ODR = 0;
volatile unsigned int GPIOA_BSRR = 0;
volatile unsigned int GPIOA_BRR = 0;


void GPIO_Init(void)
{
    GPIOA_CRL &= ~(0xFU << 20);
    GPIOA_CRL |= (0x3U << 20);

    printf("[init] GPIOA_CRL = 0X%08X\n", GPIOA_CRL);
}

void LED_On(void)
{

GPIOA_ODR |= (1U << 5);

 printf("[操作] PA5 = 高电平，LED亮 | ODR = 0x%08X\n",
           GPIOA_ODR);

}

void LED_Off(void)
{
    GPIOA_ODR &= ~(1U <<5);
    printf("[操作] PA5 = 低电平，LED灭 | ODR = 0x%08X\n",
           GPIOA_ODR);
}

int LED_GetState(void)
{

    return (GPIOA_ODR >>5) & 1U;
}




int main(void)
{


printf("STM32 GPIO simulation\n");

printf("Initial GPIOA_CRL = 0x%08X\n", GPIOA_CRL);
printf("Initial GPIOA_ODR = 0x%08X\n", GPIOA_ODR);

GPIO_Init();

 printf("After init:  GPIOA_CRL = 0x%08X\n", GPIOA_CRL);


 
printf("====================================\n");
    printf("     STM32 GPIO 模拟 - LED 闪烁\n");
    printf("====================================\n\n");

    // 初始化 GPIO，配置 PA5 为推挽输出
    GPIO_Init();

    printf("\n开始闪烁，共 10 次...\n\n");

    // 用有限循环模拟 LED 闪烁 10 次
    for (int i = 0; i < 10; i++)
    {
        LED_On();
        printf("读取状态：PA5 = %d\n", LED_GetState());

        Sleep(500);

        LED_Off();
        printf("读取状态：PA5 = %d\n", LED_GetState());

        Sleep(500);

        printf("--- 已闪烁 %d 次 ---\n\n", i + 1);
    }

    printf("模拟结束。\n");

    return 0;
}