/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 * $Id: node-id.c,v 1.1 2007/03/23 09:59:08 nifi Exp $
 */

/**
 * \file
 *         Utility to store a node id in the external flash
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "node-id.h"
#include "contiki-conf.h"
#include "dev/xmem.h"

unsigned short node_id = 0;

/*---------------------------------------------------------------------------*/
void
node_id_restore(void)
{
  /* unsigned char buf[4]; */
  /* xmem_pread(buf, 4, NODE_ID_XMEM_OFFSET); */
  /* if(buf[0] == 0xad && */
  /*    buf[1] == 0xde) { */
  /*   node_id = (buf[2] << 8) | buf[3]; */
  /* } else { */
    node_id = 0;
  /* } */
}
/*---------------------------------------------------------------------------*/
void
node_id_burn(unsigned short id)
{
  /* unsigned char buf[4]; */
  /* buf[0] = 0xad; */
  /* buf[1] = 0xde; */
  /* buf[2] = id >> 8; */
  /* buf[3] = id & 0xff; */
  //xmem_erase(XMEM_ERASE_UNIT_SIZE, NODE_ID_XMEM_OFFSET);
  //xmem_pwrite(buf, 4, NODE_ID_XMEM_OFFSET);
}
/*---------------------------------------------------------------------------*/
