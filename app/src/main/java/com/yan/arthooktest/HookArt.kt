package com.yan.arthooktest

/**
 * @author Bevan (Contact me: https://github.com/genius158)
 * @since  2020/10/25
 */
object HookArt {
    fun execute() {
        System.loadLibrary("hookart")
        hook()
    }

    private external fun hook()
}