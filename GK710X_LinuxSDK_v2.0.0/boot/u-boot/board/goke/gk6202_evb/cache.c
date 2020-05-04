/*
 * (C) Copyright 2010
 * Goke Micro Limited
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

void l2c_configure()
{
	unsigned int value = 0x1000000;
	unsigned int cfg;
	
	
	
	*((volatile unsigned int *)(0xa2200100)) = 0;
	value = *((volatile unsigned int *)(0xa2200F60));
	value |= 0x40000000;
	value &= 0xF7FFFFFF;
	value |= 0x00800000;
	*((volatile unsigned int *)(0xa2200F60)) = value;
	
	*((volatile unsigned int *)(0xa2200104)) =0x00D20000;
	*((volatile unsigned int *)(0xa2200108)) =0x0;
	*((volatile unsigned int *)(0xa220010c)) =0x0;
	*((volatile unsigned int *)(0xa2200220)) =0x000001ff;
	*((volatile unsigned int *)(0xa2200214)) =0x000001ff;
	*((volatile unsigned int *)(0xa220077c)) =0x000000ff;
	while(*((volatile unsigned int *)(0xa220077c)))
	{};
	*((volatile unsigned int *)(0xa2200100)) = 1;
	
	
	cfg = 0x00000008;
	*((volatile unsigned int *)(0xa2200208)) = cfg;
	*((volatile unsigned int *)(0xa2200200)) = 0x00000007;
	
	value = *((volatile unsigned int *)(0xa2200210)) ;
}
