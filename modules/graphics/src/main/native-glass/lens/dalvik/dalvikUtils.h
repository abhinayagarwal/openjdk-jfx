/*
 * Copyright (c) 2012, 2014, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#ifndef DALVIKUTILS_H
#define	DALVIKUTILS_H

#include "dalvikConst.h"
#include <linux/input.h>
#include <android/keycodes.h>

#ifdef	__cplusplus
extern "C" {
#endif     

#define CHECK_EXCEPTION(env) \
    if ((*env)->ExceptionCheck(env) == JNI_TRUE) {                                 \
        LOGE("Detected outstanding Java exception at %s:%s:%d\n", \
                __FUNCTION__, __FILE__, __LINE__);                                 \
        (*env)->ExceptionDescribe(env);                                            \
        (*env)->ExceptionClear(env);                                               \
    };    

int to_jfx_key_action(int action);    
int to_jfx_touch_action(int state);    
int to_linux_keycode(int androidKeyCode);
char *describe_surface_format(int format);
char *describe_touch_action(int state);
char *describe_key_action(int action);

typedef struct {
    int32_t androidKC;
    int32_t linuxKC;
} AndroidLinuxKC;

static AndroidLinuxKC keyMap[] = {
    {AKEYCODE_UNKNOWN, KEY_RESERVED},
    {AKEYCODE_0, KEY_0},
    {AKEYCODE_1, KEY_1},
    {AKEYCODE_2, KEY_2},
    {AKEYCODE_3, KEY_3},
    {AKEYCODE_4, KEY_4},
    {AKEYCODE_5, KEY_5},
    {AKEYCODE_6, KEY_6},
    {AKEYCODE_7, KEY_7},
    {AKEYCODE_8, KEY_8},
    {AKEYCODE_9, KEY_9},
    {AKEYCODE_MINUS, KEY_MINUS},
    {AKEYCODE_EQUALS, KEY_EQUAL},
    {AKEYCODE_TAB, KEY_TAB},
    {AKEYCODE_Q, KEY_Q},
    {AKEYCODE_W, KEY_W},
    {AKEYCODE_E, KEY_E},
    {AKEYCODE_R, KEY_R},
    {AKEYCODE_T, KEY_T},
    {AKEYCODE_Y, KEY_Y},
    {AKEYCODE_U, KEY_U},
    {AKEYCODE_I, KEY_I},
    {AKEYCODE_O, KEY_O},
    {AKEYCODE_P, KEY_P},
    {AKEYCODE_LEFT_BRACKET, KEY_LEFTBRACE},
    {AKEYCODE_RIGHT_BRACKET, KEY_RIGHTBRACE},
    {AKEYCODE_ENTER, KEY_ENTER},
    //{AKEYCODE_CTRL_LEFT, KEY_LEFTCTRL},
    //{AKEYCODE_CTRL_RIGHT, KEY_RIGHTCTRL},
    {AKEYCODE_A, KEY_A},
    {AKEYCODE_S, KEY_S},
    {AKEYCODE_D, KEY_D},
    {AKEYCODE_F, KEY_F},
    {AKEYCODE_G, KEY_G},
    {AKEYCODE_H, KEY_H},
    {AKEYCODE_J, KEY_J},
    {AKEYCODE_K, KEY_K},
    {AKEYCODE_L, KEY_L},
    {AKEYCODE_SEMICOLON, KEY_SEMICOLON},
    {AKEYCODE_GRAVE, KEY_GRAVE},
    {AKEYCODE_SHIFT_LEFT, KEY_LEFTSHIFT},
    {AKEYCODE_BACKSLASH, KEY_BACKSLASH},
    {AKEYCODE_Z, KEY_Z},
    {AKEYCODE_X, KEY_X},
    {AKEYCODE_C, KEY_C},
    {AKEYCODE_V, KEY_V},
    {AKEYCODE_B, KEY_B},
    {AKEYCODE_N, KEY_N},
    {AKEYCODE_M, KEY_M},
    {AKEYCODE_APOSTROPHE, KEY_APOSTROPHE},
    {AKEYCODE_COMMA, KEY_COMMA},
    {AKEYCODE_PERIOD, KEY_DOT},
    {AKEYCODE_SLASH, KEY_SLASH},
    {AKEYCODE_SHIFT_RIGHT, KEY_RIGHTSHIFT},
    {AKEYCODE_STAR, KEY_KPASTERISK},
    {AKEYCODE_ALT_LEFT, KEY_LEFTALT},
    {AKEYCODE_SPACE, KEY_SPACE},
    //{AKEYCODE_CAPSLOCK, KEY_CAPSLOCK},
    //{AKEYCODE_CTRL_RIGHT, KEY_RIGHTCTRL},
    {AKEYCODE_ALT_RIGHT, KEY_RIGHTALT},
    {AKEYCODE_HOME, KEY_HOME},
    {AKEYCODE_BACK, KEY_ESC},           //special back key mapped to ESC
    {AKEYCODE_DPAD_UP, KEY_UP},
    {AKEYCODE_PAGE_UP, KEY_PAGEUP},
    {AKEYCODE_DPAD_LEFT, KEY_LEFT},
    {AKEYCODE_DPAD_RIGHT, KEY_RIGHT},
    //{AKEYCODE_END, KEY_END},
    {AKEYCODE_DPAD_DOWN, KEY_DOWN},
    {AKEYCODE_PAGE_DOWN, KEY_PAGEDOWN},
    //{AKEYCODE_INSERT, KEY_INSERT},
    {AKEYCODE_DEL, KEY_BACKSPACE},
    {AKEYCODE_FORWARD_DEL, KEY_DELETE},
    {AKEYCODE_MENU, KEY_MENU },
};
    

#ifdef	__cplusplus
}
#endif

#endif	/* DALVIKUTILS_H */
