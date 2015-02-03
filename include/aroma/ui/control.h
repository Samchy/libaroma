/********************************************************************[libaroma]*
 * Copyright (C) 2011-2015 Ahmad Amarullah (http://amarullz.com/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *______________________________________________________________________________
 *
 * Filename    : control.h
 * Description : window control manager
 *
 * + This is part of libaroma, an embedded ui toolkit.
 * + 28/01/15 - Author(s): Ahmad Amarullah
 *
 */
#ifndef __libaroma_aroma_h__
  #error "Include <aroma.h> instead."
#endif
#ifndef __libaroma_control_h__
#define __libaroma_control_h__


/*
 * Typedef     : LIBAROMA_CTLCB_*
 * Descriptions: control callbacks
 */
typedef byte (*LIBAROMA_CTLCB_MESSAGE) \
  (LIBAROMA_CONTROLP, LIBAROMA_MSGP);
typedef void (*LIBAROMA_CTLCB_DRAW) \
  (LIBAROMA_CONTROLP, LIBAROMA_CANVASP);
typedef byte (*LIBAROMA_CTLCB_FOCUS) \
  (LIBAROMA_CONTROLP, byte);
typedef void (*LIBAROMA_CTLCB_DESTROY) \
  (LIBAROMA_CONTROLP);

/*
 * Structure   : _LIBAROMA_CONTROL
 * Typedef     : LIBAROMA_CONTROL, * LIBAROMA_CONTROLP
 * Descriptions: control structure
 */
struct _LIBAROMA_CONTROL{
  byte signature;
  word id;
  voidp internal;
  LIBAROMA_WINDOWP window;
  int x;
  int y;
  int w;
  int h;
  /* callbacks */
  LIBAROMA_CTLCB_MESSAGE message;
  LIBAROMA_CTLCB_DRAW draw;
  LIBAROMA_CTLCB_FOCUS focus;
  LIBAROMA_CTLCB_DESTROY destroy;
};

/*
 * Function    : libaroma_control_new
 * Return Value: LIBAROMA_CONTROLP
 * Descriptions: create primitive control
 */
LIBAROMA_CONTROLP libaroma_control_new(
  byte signature, word id,
  int x, int y, int w, int h,
  LIBAROMA_CTLCB_MESSAGE message,
  LIBAROMA_CTLCB_DRAW draw,
  LIBAROMA_CTLCB_FOCUS focus,
  LIBAROMA_CTLCB_DESTROY destroy
);

/*
 * Function    : libaroma_control_draw_flush
 * Return Value: byte
 * Descriptions: draw control into window
 */
byte libaroma_control_draw_flush(
  LIBAROMA_CONTROLP ctl,
  LIBAROMA_CANVASP canvas,
  byte sync
);

/*
 * Function    : libaroma_control_erasebg
 * Return Value: byte
 * Descriptions: erase control background
 */
byte libaroma_control_erasebg(
  LIBAROMA_CONTROLP ctl,
  LIBAROMA_CANVASP canvas
);

/*
 * Function    : libaroma_control_isvisible
 * Return Value: byte
 * Descriptions: check if control visible
 */
byte libaroma_control_isvisible(LIBAROMA_CONTROLP ctl);

/*
 * Function    : libaroma_control_draw_begin
 * Return Value: LIBAROMA_CANVASP
 * Descriptions: begin control ondraw
 */
LIBAROMA_CANVASP libaroma_control_draw_begin(
  LIBAROMA_CONTROLP ctl);

/*
 * Function    : libaroma_control_draw_end
 * Return Value: void
 * Descriptions: end control ondraw
 */
void libaroma_control_draw_end(
  LIBAROMA_CONTROLP ctl, LIBAROMA_CANVASP c, byte sync
);

/*
 * Function    : libaroma_control_draw
 * Return Value: byte
 * Descriptions: draw control
 */
byte libaroma_control_draw(
  LIBAROMA_CONTROLP ctl, byte sync
);

/*
 * Function    : libaroma_control_free
 * Return Value: byte
 * Descriptions: free control
 */
byte libaroma_control_free(
  LIBAROMA_CONTROLP ctl
);


#endif /* __libaroma_control_h__ */