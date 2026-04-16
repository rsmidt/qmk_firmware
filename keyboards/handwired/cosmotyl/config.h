#pragma once

/* Enable EEPROM hands configuration */
#define EE_HANDS

/* Configure SPI for the pointing device (trackball) */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19
#define POINTING_DEVICE_CS_PIN GP29
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_X

/* Enable Unicode input */
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

/*
 * Urob's Timeless Home Row Mods
 * from: https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/
 * Noticeable delay when tapping HRMs: Increase FLOW_TAP_TERM.
 * False negatives (same-hand): Reduce TAPPING_TERM (or disable Chordal Hold)
 * False negatives (cross-hand): Reduce FLOW_TAP_TERM
 * False positives (same-hand): Increase TAPPING_TERM
 * False positives (cross-hand): Increase FLOW_TAP_TERM
 */
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define SPECULATIVE_HOLD
