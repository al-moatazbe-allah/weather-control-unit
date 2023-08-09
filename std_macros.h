/*
 * std_macros.h
 *
 * Created: 2/2/2023 8:30:23 PM
 *  Author: dell
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define REGISTER_SIZE 8
#define READ_BIT(REG,BIT) ((REG&(1<<BIT))>>BIT)
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=(~(1<<BIT))
#define TOG_BIT(REG,BIT) REG^=(1<<BIT)
#define IS_BIT_SET(REG,BIT)  ((REG&(1<<BIT))>>BIT)
#define IS_BIT_CLR(REG,BIT)  !((REG&(1<<BIT))>>BIT)
#define ROR(REG,BIT)         REG=(REG<<(REGISTER_SIZE-BIT))|(REG>>(BIT))
#define ROL(REG,BIT)         REG=(REG>>(REGISTER_SIZE-BIT))|(REG<<(BIT))
typedef unsigned char u_8int;
typedef signed char _8int;

#endif /* STD_MACROS_H_ */