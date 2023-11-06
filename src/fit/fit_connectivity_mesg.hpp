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


#if !defined(FIT_CONNECTIVITY_MESG_HPP)
#define FIT_CONNECTIVITY_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class ConnectivityMesg : public Mesg
{
public:
    class FieldDefNum final
    {
    public:
       static const FIT_UINT8 BluetoothEnabled = 0;
       static const FIT_UINT8 BluetoothLeEnabled = 1;
       static const FIT_UINT8 AntEnabled = 2;
       static const FIT_UINT8 Name = 3;
       static const FIT_UINT8 LiveTrackingEnabled = 4;
       static const FIT_UINT8 WeatherConditionsEnabled = 5;
       static const FIT_UINT8 WeatherAlertsEnabled = 6;
       static const FIT_UINT8 AutoActivityUploadEnabled = 7;
       static const FIT_UINT8 CourseDownloadEnabled = 8;
       static const FIT_UINT8 WorkoutDownloadEnabled = 9;
       static const FIT_UINT8 GpsEphemerisDownloadEnabled = 10;
       static const FIT_UINT8 IncidentDetectionEnabled = 11;
       static const FIT_UINT8 GrouptrackEnabled = 12;
       static const FIT_UINT8 Invalid = FIT_FIELD_NUM_INVALID;
    };

    ConnectivityMesg(void) : Mesg(Profile::MESG_CONNECTIVITY)
    {
    }

    ConnectivityMesg(const Mesg &mesg) : Mesg(mesg)
    {
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of bluetooth_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsBluetoothEnabledValid() const
    {
        const Field* field = GetField(0);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns bluetooth_enabled field
    // Comment: Use Bluetooth for connectivity features
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetBluetoothEnabled(void) const
    {
        return GetFieldENUMValue(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set bluetooth_enabled field
    // Comment: Use Bluetooth for connectivity features
    ///////////////////////////////////////////////////////////////////////
    void SetBluetoothEnabled(FIT_BOOL bluetoothEnabled)
    {
        SetFieldENUMValue(0, bluetoothEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of bluetooth_le_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsBluetoothLeEnabledValid() const
    {
        const Field* field = GetField(1);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns bluetooth_le_enabled field
    // Comment: Use Bluetooth Low Energy for connectivity features
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetBluetoothLeEnabled(void) const
    {
        return GetFieldENUMValue(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set bluetooth_le_enabled field
    // Comment: Use Bluetooth Low Energy for connectivity features
    ///////////////////////////////////////////////////////////////////////
    void SetBluetoothLeEnabled(FIT_BOOL bluetoothLeEnabled)
    {
        SetFieldENUMValue(1, bluetoothLeEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of ant_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAntEnabledValid() const
    {
        const Field* field = GetField(2);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns ant_enabled field
    // Comment: Use ANT for connectivity features
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetAntEnabled(void) const
    {
        return GetFieldENUMValue(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set ant_enabled field
    // Comment: Use ANT for connectivity features
    ///////////////////////////////////////////////////////////////////////
    void SetAntEnabled(FIT_BOOL antEnabled)
    {
        SetFieldENUMValue(2, antEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of name field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsNameValid() const
    {
        const Field* field = GetField(3);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns name field
    ///////////////////////////////////////////////////////////////////////
    FIT_WSTRING GetName(void) const
    {
        return GetFieldSTRINGValue(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set name field
    ///////////////////////////////////////////////////////////////////////
    void SetName(FIT_WSTRING name)
    {
        SetFieldSTRINGValue(3, name, 0);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of live_tracking_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsLiveTrackingEnabledValid() const
    {
        const Field* field = GetField(4);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns live_tracking_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetLiveTrackingEnabled(void) const
    {
        return GetFieldENUMValue(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set live_tracking_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetLiveTrackingEnabled(FIT_BOOL liveTrackingEnabled)
    {
        SetFieldENUMValue(4, liveTrackingEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of weather_conditions_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsWeatherConditionsEnabledValid() const
    {
        const Field* field = GetField(5);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns weather_conditions_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetWeatherConditionsEnabled(void) const
    {
        return GetFieldENUMValue(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set weather_conditions_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetWeatherConditionsEnabled(FIT_BOOL weatherConditionsEnabled)
    {
        SetFieldENUMValue(5, weatherConditionsEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of weather_alerts_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsWeatherAlertsEnabledValid() const
    {
        const Field* field = GetField(6);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns weather_alerts_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetWeatherAlertsEnabled(void) const
    {
        return GetFieldENUMValue(6, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set weather_alerts_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetWeatherAlertsEnabled(FIT_BOOL weatherAlertsEnabled)
    {
        SetFieldENUMValue(6, weatherAlertsEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of auto_activity_upload_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsAutoActivityUploadEnabledValid() const
    {
        const Field* field = GetField(7);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns auto_activity_upload_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetAutoActivityUploadEnabled(void) const
    {
        return GetFieldENUMValue(7, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set auto_activity_upload_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetAutoActivityUploadEnabled(FIT_BOOL autoActivityUploadEnabled)
    {
        SetFieldENUMValue(7, autoActivityUploadEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of course_download_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsCourseDownloadEnabledValid() const
    {
        const Field* field = GetField(8);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns course_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetCourseDownloadEnabled(void) const
    {
        return GetFieldENUMValue(8, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set course_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetCourseDownloadEnabled(FIT_BOOL courseDownloadEnabled)
    {
        SetFieldENUMValue(8, courseDownloadEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of workout_download_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsWorkoutDownloadEnabledValid() const
    {
        const Field* field = GetField(9);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns workout_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetWorkoutDownloadEnabled(void) const
    {
        return GetFieldENUMValue(9, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set workout_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetWorkoutDownloadEnabled(FIT_BOOL workoutDownloadEnabled)
    {
        SetFieldENUMValue(9, workoutDownloadEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of gps_ephemeris_download_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsGpsEphemerisDownloadEnabledValid() const
    {
        const Field* field = GetField(10);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns gps_ephemeris_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetGpsEphemerisDownloadEnabled(void) const
    {
        return GetFieldENUMValue(10, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set gps_ephemeris_download_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetGpsEphemerisDownloadEnabled(FIT_BOOL gpsEphemerisDownloadEnabled)
    {
        SetFieldENUMValue(10, gpsEphemerisDownloadEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of incident_detection_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsIncidentDetectionEnabledValid() const
    {
        const Field* field = GetField(11);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns incident_detection_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetIncidentDetectionEnabled(void) const
    {
        return GetFieldENUMValue(11, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set incident_detection_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetIncidentDetectionEnabled(FIT_BOOL incidentDetectionEnabled)
    {
        SetFieldENUMValue(11, incidentDetectionEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Checks the validity of grouptrack_enabled field
    // Returns FIT_TRUE if field is valid
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL IsGrouptrackEnabledValid() const
    {
        const Field* field = GetField(12);
        if( FIT_NULL == field )
        {
            return FIT_FALSE;
        }

        return field->IsValueValid();
    }

    ///////////////////////////////////////////////////////////////////////
    // Returns grouptrack_enabled field
    ///////////////////////////////////////////////////////////////////////
    FIT_BOOL GetGrouptrackEnabled(void) const
    {
        return GetFieldENUMValue(12, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

    ///////////////////////////////////////////////////////////////////////
    // Set grouptrack_enabled field
    ///////////////////////////////////////////////////////////////////////
    void SetGrouptrackEnabled(FIT_BOOL grouptrackEnabled)
    {
        SetFieldENUMValue(12, grouptrackEnabled, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
    }

};

} // namespace fit

#endif // !defined(FIT_CONNECTIVITY_MESG_HPP)
