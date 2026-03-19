#include<stm32l476xx.h>

#define LED 5
#define BOUTON 6
int main(void)
{ 
  RCC->AHB2ENR |=RCC_AHB2ENR_GPIOAEN;

  GPIOA->MODER &= ~(3<<(LED*2));
  GPIOA->MODER |=(1<<(LED*2));

  GPIOA->MODER &= ~(3<<(BOUTON*2));
  GPIOA->PUPDR &=~(3<<(BOUTON*2));
  GPIOA->PUPDR |= (1<<(BOUTON*2));

  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

  SYSCFG->EXTICR[1] &= ~(SYSCFG_EXTICR2_EXTI6);
  SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI6_PA;

  EXTI->FTSR1 |= EXTI_FTSR1_FT6;

  EXTI->IMR1 |= EXTI_IMR1_IM6;

  NVIC_EnableIRQ(EXTI9_5_IRQn);

  while (1)
  {
  }
}
void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR1 & EXTI_PR1_PIF6)
    {
        EXTI->PR1 |= EXTI_PR1_PIF6;

        GPIOA->ODR ^= (1<<LED);
    }
}


