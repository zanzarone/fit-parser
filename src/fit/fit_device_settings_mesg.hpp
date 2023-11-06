////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Garmin Canada Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2021 Garmin International, Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.67Release+Custom
// Tag = production/akw/21.67.00-0-gd790f76b
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_DEVICE_SETTINGS_MESG_HPP)
#define FIT_DEVICE_SETTINGS_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class DeviceSettingsMesg : public Mesg
{
public:
    class FieldDefNum final
    {
    public:
       static const FIT_UINT8 ActiveTimeZone = 0;
       static const FIT_UINT8 UtcOffset = 1;
       static const FIT_UINT8 TimeOffset = 2;
       static const FIT_UINT8 TimeMode = 4;
       static const FIT_UINT8 TimeZoneOffset = 5;
       static const FIT_UINT8 BacklightMode = 12;
       static const FIT_UINT8 ActivityTrackerEnabled = 36;
       static const FIT_UINT8 ClockTime = 39;
       static const FIT_UINT8 PagesEnabled = 40;
       static const FIT_UINT8 MoveAlertEnabled = 46;
       static const FIT_UINT8 DateMode = 47;
       static const FIT_UINT8 DisplayOrientation = 55;
       static const FIT_UINT8 MountingSide = 56;
       static const FIT_UINT8 DefaultPage = 57;
       static const FIT_UINT8 AutosyncMinSteps = 58;
       static const FIT_UINT8 AutosyncMinTime = 59;
       static const FIT_UINT8 LactateThresholdAutodetectEnabled = 80;
       static const FIT_UINT8 BleAutoUploadEnabled = 86;
       static const FIT_UINT8 AutoSyncFrequency = 89;
       static const FIT_UINT8 AutoActivityDetect = 90;
       static const FIT_UINT8 NumberOfScreens = 94;
       static const FIT_UINT8 SmartNotificationDisplayOrientation = 95;
       static const FIT_UINT8 TapInterface = 134;
       static const FIT_UINT8 TapSensitivity = 174;
       static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    DeviceSettingsMesg(void) : Mesg(Profile::MESG_DEVICE_SETTINGS)
    {
    }

    DeviceSettingsMesg(const Mesg &mesg) : Mesg(mesg)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of active_time_zone field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsActiveTimeZoneValid() const
    {
        const Field* field = GetField(0);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns active_time_zone field
    // Comment: Index into time zone arrays.
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetActiveTimeZone(void) const
    {
        return GetFieldUINT8Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set active_time_zone field
    // Comment: Index into time zone arrays.
    ///////////////////////////////////////////////////////////////////////
    void SetActiveTimeZone(FIT_UINT8 activeTimeZone)
    {
        SetFieldUINT8Value(0, activeTimeZone, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of utc_offset field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsUtcOffsetValid() const
    {
        const Field* field = GetField(1);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns utc_offset field
    // Comment: Offset from system time. Required to convert timestamp from system time to UTC.
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetUtcOffset(void) const
    {
        return GetFieldUINT32Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set utc_offset field
    // Comment: Offset from system time. Required to convert timestamp from system time to UTC.
    ///////////////////////////////////////////////////////////////////////
    void SetUtcOffset(FIT_UINT32 utcOffset)
    {
        SetFieldUINT32Value(1, utcOffset, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of time_offset
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumTimeOffset(void) const
    {
        return GetFieldNumValues(2, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of time_offset field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimeOffsetValid(FIT_UINT8 index) const
    {
        const Field* field = GetField(2);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns time_offset field
    // Units: s
    // Comment: Offset from system time.
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT32 GetTimeOffset(FIT_UINT8 index) const
    {
        return GetFieldUINT32Value(2, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set time_offset field
    // Units: s
    // Comment: Offset from system time.
    ///////////////////////////////////////////////////////////////////////
    void SetTimeOffset(FIT_UINT8 index, FIT_UINT32 timeOffset)
    {
        SetFieldUINT32Value(2, timeOffset, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of time_mode
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumTimeMode(void) const
    {
        return GetFieldNumValues(4, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of time_mode field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimeModeValid(FIT_UINT8 index) const
    {
        const Field* field = GetField(4);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns time_mode field
    // Comment: Display mode for the time
    ///////////////////////////////////////////////////////////////////////
    FIT_TIME_MODE GetTimeMode(FIT_UINT8 index) const
    {
        return GetFieldENUMValue(4, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set time_mode field
    // Comment: Display mode for the time
    ///////////////////////////////////////////////////////////////////////
    void SetTimeMode(FIT_UINT8 index, FIT_TIME_MODE timeMode)
    {
        SetFieldENUMValue(4, timeMode, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of time_zone_offset
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumTimeZoneOffset(void) const
    {
        return GetFieldNumValues(5, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of time_zone_offset field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTimeZoneOffsetValid(FIT_UINT8 index) const
    {
        const Field* field = GetField(5);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns time_zone_offset field
    // Units: hr
    // Comment: timezone offset in 1/4 hour increments
    ///////////////////////////////////////////////////////////////////////
    FIT_FLOAT32 GetTimeZoneOffset(FIT_UINT8 index) const
    {
        return GetFieldFLOAT32Value(5, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set time_zone_offset field
    // Units: hr
    // Comment: timezone offset in 1/4 hour increments
    ///////////////////////////////////////////////////////////////////////
    void SetTimeZoneOffset(FIT_UINT8 index, FIT_FLOAT32 timeZoneOffset)
    {
        SetFieldFLOAT32Value(5, timeZoneOffset, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of backlight_mode field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsBacklightModeValid() const
    {
        const Field* field = GetField(12);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns backlight_mode field
    // Comment: Mode for backlight
    ///////////////////////////////////////////////////////////////////////
    FIT_BACKLIGHT_MODE GetBacklightMode(void) const
    {
        return GetFieldENUMValue(12, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set backlight_mode field
    // Comment: Mode for backlight
    ///////////////////////////////////////////////////////////////////////
    void SetBacklightMode(FIT_BACKLIGHT_MODE backlightMode)
    {
        SetFieldENUMValue(12, backlightMode, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of activity_tracker_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsActivityTrackerEnabledValid() const
    {
        const Field* field = GetField(36);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns activity_tracker_enabled field
    // Comment: Enabled state of the activity tracker functionality
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetActivityTrackerEnabled(void) const
    {
        return GetFieldENUMValue(36, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set activity_tracker_enabled field
    // Comment: Enabled state of the activity tracker functionality
    ///////////////////////////////////////////////////////////////////////
    void SetActivityTrackerEnabled(FIT_BOOL activityTrackerEnabled)
    {
        SetFieldENUMValue(36, activityTrackerEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of clock_time field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsClockTimeValid() const
    {
        const Field* field = GetField(39);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns clock_time field
    // Comment: UTC timestamp used to set the devices clock and date
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_TIME GetClockTime(void) const
    {
        return GetFieldUINT32Value(39, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set clock_time field
    // Comment: UTC timestamp used to set the devices clock and date
    ///////////////////////////////////////////////////////////////////////
    void SetClockTime(FIT_DATE_TIME clockTime)
    {
        SetFieldUINT32Value(39, clockTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of pages_enabled
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumPagesEnabled(void) const
    {
        return GetFieldNumValues(40, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of pages_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsPagesEnabledValid(FIT_UINT8 index) const
    {
        const Field* field = GetField(40);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns pages_enabled field
    // Comment: Bitfield  to configure enabled screens for each supported loop
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetPagesEnabled(FIT_UINT8 index) const
    {
        return GetFieldUINT16Value(40, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set pages_enabled field
    // Comment: Bitfield  to configure enabled screens for each supported loop
    ///////////////////////////////////////////////////////////////////////
    void SetPagesEnabled(FIT_UINT8 index, FIT_UINT16 pagesEnabled)
    {
        SetFieldUINT16Value(40, pagesEnabled, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of move_alert_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMoveAlertEnabledValid() const
    {
        const Field* field = GetField(46);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns move_alert_enabled field
    // Comment: Enabled state of the move alert
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetMoveAlertEnabled(void) const
    {
        return GetFieldENUMValue(46, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set move_alert_enabled field
    // Comment: Enabled state of the move alert
    ///////////////////////////////////////////////////////////////////////
    void SetMoveAlertEnabled(FIT_BOOL moveAlertEnabled)
    {
        SetFieldENUMValue(46, moveAlertEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of date_mode field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDateModeValid() const
    {
        const Field* field = GetField(47);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns date_mode field
    // Comment: Display mode for the date
    ///////////////////////////////////////////////////////////////////////
    FIT_DATE_MODE GetDateMode(void) const
    {
        return GetFieldENUMValue(47, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set date_mode field
    // Comment: Display mode for the date
    ///////////////////////////////////////////////////////////////////////
    void SetDateMode(FIT_DATE_MODE dateMode)
    {
        SetFieldENUMValue(47, dateMode, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of display_orientation field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDisplayOrientationValid() const
    {
        const Field* field = GetField(55);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns display_orientation field
    ///////////////////////////////////////////////////////////////////////
    FIT_DISPLAY_ORIENTATION GetDisplayOrientation(void) const
    {
        return GetFieldENUMValue(55, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set display_orientation field
    ///////////////////////////////////////////////////////////////////////
    void SetDisplayOrientation(FIT_DISPLAY_ORIENTATION displayOrientation)
    {
        SetFieldENUMValue(55, displayOrientation, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of mounting_side field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsMountingSideValid() const
    {
        const Field* field = GetField(56);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns mounting_side field
    ///////////////////////////////////////////////////////////////////////
    FIT_SIDE GetMountingSide(void) const
    {
        return GetFieldENUMValue(56, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set mounting_side field
    ///////////////////////////////////////////////////////////////////////
    void SetMountingSide(FIT_SIDE mountingSide)
    {
        SetFieldENUMValue(56, mountingSide, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number of default_page
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumDefaultPage(void) const
    {
        return GetFieldNumValues(57, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of default_page field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsDefaultPageValid(FIT_UINT8 index) const
    {
        const Field* field = GetField(57);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid(index);
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns default_page field
    // Comment: Bitfield to indicate one page as default for each supported loop
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetDefaultPage(FIT_UINT8 index) const
    {
        return GetFieldUINT16Value(57, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set default_page field
    // Comment: Bitfield to indicate one page as default for each supported loop
    ///////////////////////////////////////////////////////////////////////
    void SetDefaultPage(FIT_UINT8 index, FIT_UINT16 defaultPage)
    {
        SetFieldUINT16Value(57, defaultPage, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of autosync_min_steps field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAutosyncMinStepsValid() const
    {
        const Field* field = GetField(58);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns autosync_min_steps field
    // Units: steps
    // Comment: Minimum steps before an autosync can occur
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetAutosyncMinSteps(void) const
    {
        return GetFieldUINT16Value(58, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set autosync_min_steps field
    // Units: steps
    // Comment: Minimum steps before an autosync can occur
    ///////////////////////////////////////////////////////////////////////
    void SetAutosyncMinSteps(FIT_UINT16 autosyncMinSteps)
    {
        SetFieldUINT16Value(58, autosyncMinSteps, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of autosync_min_time field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAutosyncMinTimeValid() const
    {
        const Field* field = GetField(59);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns autosync_min_time field
    // Units: minutes
    // Comment: Minimum minutes before an autosync can occur
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT16 GetAutosyncMinTime(void) const
    {
        return GetFieldUINT16Value(59, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set autosync_min_time field
    // Units: minutes
    // Comment: Minimum minutes before an autosync can occur
    ///////////////////////////////////////////////////////////////////////
    void SetAutosyncMinTime(FIT_UINT16 autosyncMinTime)
    {
        SetFieldUINT16Value(59, autosyncMinTime, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of lactate_threshold_autodetect_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsLactateThresholdAutodetectEnabledValid() const
    {
        const Field* field = GetField(80);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns lactate_threshold_autodetect_enabled field
    // Comment: Enable auto-detect setting for the lactate threshold feature.
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetLactateThresholdAutodetectEnabled(void) const
    {
        return GetFieldENUMValue(80, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set lactate_threshold_autodetect_enabled field
    // Comment: Enable auto-detect setting for the lactate threshold feature.
    ///////////////////////////////////////////////////////////////////////
    void SetLactateThresholdAutodetectEnabled(FIT_BOOL lactateThresholdAutodetectEnabled)
    {
        SetFieldENUMValue(80, lactateThresholdAutodetectEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of ble_auto_upload_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsBleAutoUploadEnabledValid() const
    {
        const Field* field = GetField(86);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns ble_auto_upload_enabled field
    // Comment: Automatically upload using BLE
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetBleAutoUploadEnabled(void) const
    {
        return GetFieldENUMValue(86, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set ble_auto_upload_enabled field
    // Comment: Automatically upload using BLE
    ///////////////////////////////////////////////////////////////////////
    void SetBleAutoUploadEnabled(FIT_BOOL bleAutoUploadEnabled)
    {
        SetFieldENUMValue(86, bleAutoUploadEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of auto_sync_frequency field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAutoSyncFrequencyValid() const
    {
        const Field* field = GetField(89);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns auto_sync_frequency field
    // Comment: Helps to conserve battery by changing modes
    ///////////////////////////////////////////////////////////////////////
    FIT_AUTO_SYNC_FREQUENCY GetAutoSyncFrequency(void) const
    {
        return GetFieldENUMValue(89, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set auto_sync_frequency field
    // Comment: Helps to conserve battery by changing modes
    ///////////////////////////////////////////////////////////////////////
    void SetAutoSyncFrequency(FIT_AUTO_SYNC_FREQUENCY autoSyncFrequency)
    {
        SetFieldENUMValue(89, autoSyncFrequency, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of auto_activity_detect field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAutoActivityDetectValid() const
    {
        const Field* field = GetField(90);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns auto_activity_detect field
    // Comment: Allows setting specific activities auto-activity detect enabled/disabled settings
    ///////////////////////////////////////////////////////////////////////
    FIT_AUTO_ACTIVITY_DETECT GetAutoActivityDetect(void) const
    {
        return GetFieldUINT32Value(90, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set auto_activity_detect field
    // Comment: Allows setting specific activities auto-activity detect enabled/disabled settings
    ///////////////////////////////////////////////////////////////////////
    void SetAutoActivityDetect(FIT_AUTO_ACTIVITY_DETECT autoActivityDetect)
    {
        SetFieldUINT32Value(90, autoActivityDetect, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of number_of_screens field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsNumberOfScreensValid() const
    {
        const Field* field = GetField(94);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns number_of_screens field
    // Comment: Number of screens configured to display
    ///////////////////////////////////////////////////////////////////////
    FIT_UINT8 GetNumberOfScreens(void) const
    {
        return GetFieldUINT8Value(94, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set number_of_screens field
    // Comment: Number of screens configured to display
    ///////////////////////////////////////////////////////////////////////
    void SetNumberOfScreens(FIT_UINT8 numberOfScreens)
    {
        SetFieldUINT8Value(94, numberOfScreens, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of smart_notification_display_orientation field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsSmartNotificationDisplayOrientationValid() const
    {
        const Field* field = GetField(95);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns smart_notification_display_orientation field
    // Comment: Smart Notification display orientation
    ///////////////////////////////////////////////////////////////////////
    FIT_DISPLAY_ORIENTATION GetSmartNotificationDisplayOrientation(void) const
    {
        return GetFieldENUMValue(95, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set smart_notification_display_orientation field
    // Comment: Smart Notification display orientation
    ///////////////////////////////////////////////////////////////////////
    void SetSmartNotificationDisplayOrientation(FIT_DISPLAY_ORIENTATION smartNotificationDisplayOrientation)
    {
        SetFieldENUMValue(95, smartNotificationDisplayOrientation, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of tap_interface field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTapInterfaceValid() const
    {
        const Field* field = GetField(134);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns tap_interface field
    ///////////////////////////////////////////////////////////////////////
    FIT_SWITCH GetTapInterface(void) const
    {
        return GetFieldENUMValue(134, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set tap_interface field
    ///////////////////////////////////////////////////////////////////////
    void SetTapInterface(FIT_SWITCH tapInterface)
    {
        SetFieldENUMValue(134, tapInterface, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of tap_sensitivity field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsTapSensitivityValid() const
    {
        const Field* field = GetField(174);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns tap_sensitivity field
    // Comment: Used to hold the tap threshold setting
    ///////////////////////////////////////////////////////////////////////
    FIT_TAP_SENSITIVITY GetTapSensitivity(void) const
    {
        return GetFieldENUMValue(174, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set tap_sensitivity field
    // Comment: Used to hold the tap threshold setting
    ///////////////////////////////////////////////////////////////////////
    void SetTapSensitivity(FIT_TAP_SENSITIVITY tapSensitivity)
    {
        SetFieldENUMValue(174, tapSensitivity, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

};

} // namespace fit

#endif // !defined(FIT_DEVICE_SETTINGS_MESG_HPP)
