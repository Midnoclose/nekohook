
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

// Default drm state
#ifndef DRM_ENABLED
#if defined(BUILD_DEBUG)
#define DRM_ENABLED 0
#else
#define DRM_ENABLED 1
#endif  // if defined(BUILD_DEBUG)
#endif  // ifndef DRM_ENABLED
// Default drm values
#ifndef DRM_EXPIRES
#define DRM_EXPIRES 0  // Default value is 2 days
#endif

// Drm Defines
#if DRM_ENABLED == 1

//
// Our expiary check, Needs to be fixed
#if not DRM_EXPIRES == 0
#define DRM_EXPIRE ((time(0) - DRM_EXPIRES) > 0)
#else
#define DRM_EXPIRE false
#endif

#define DRM_ENFORCE \
    if (DRM_CHECK_HWID || DRM_EXPIRE) (*((int*)0) = 0)

#else

// The point is for this to get optimised out
#define DRM_ENFORCE \
    if (false) {    \
    }

#endif
