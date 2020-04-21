/*
 * utils.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: vip
 */

#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_

//FOR ALL GEGISTER BITS
#define SET_REG(var)           var=0xFF
#define CLR_REG(var)           var=0x00
#define TOG_REG(vaar)          var^=0xFF
#define ASSIGN_REG(var,Value)  var=Value

/*//ask
#define SET_BITS_REG(Reg,Mask)   Reg|=(Mask)
#define CLEAR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))
*/
//FOR BIT IN REGISTER
#define SET_BIT(var,bit)       (var|=(1<<bit))
#define CLR_BIT(var,bit)       (var&=(~(1<<bit)))
#define TOG_BIT(var,bit)       (var^=(1<<bit))
#define GET_BIT(var,bit)       ((var>>bit)&1)

//FOR NIBBLE BIT HIGH
#define  SET_NippleH(var)          (var|=0xf0 )
#define  CLR_NippleH(var)          (var&=0x0f)
#define  TOG_NippleH(var)          (var^=0xfo)
#define  GET_NippleH(var)          ((var&0xf0)>>4)
#define ASSIGN_NippleH(var,Value)  (var=((var&0x0f)|(Value&0xf0)))
//FOR NIBBLE BIT LOW
#define  SET_NippleL(var)          (var|=0x0f )
#define  CLR_NippleL(var)          (var&=0xf0)
#define  TOG_NippleL(var)          (var^=0x0f)
#define  GET_NippleL(var)          (var&0x0f)
#define ASSIGN_NippleL(var,Value)  (var=((var&0xF0)|(Value&0x0F)))
#endif /* LIB_UTILS_H_ */
