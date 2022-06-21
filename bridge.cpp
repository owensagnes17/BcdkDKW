/*
 * This file is a part of Telegram X
 * Copyright © 2014-2022 (tgx-android@pm.me)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * File created on 18/01/2021
 */

#include <jni_utils.h>
#include <log.h>

#include "bridge.h"

  loge(TAG_NDK, "[FATAL ERROR] %s, cause:%d", message.c_str(), cause);
  jclass cls = jni_class::get(env, "org/drinkmore/Tracer");
  jmethodID on_fatal_error_method = env->GetStaticMethodID(cls, "onFatalError", "(Ljava/lang/String;I)V");
    jstring error_str = jni::to_jstring(env, message.c_str());
    env->CallStaticVoidMethod(cls, on_fatal_error_method, error_str, cause);
    if (error_str) {
      env->DeleteLocalRef(error_str);
    }
  }
}
