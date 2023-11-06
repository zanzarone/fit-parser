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


#include "fit_factory.hpp"
#include "fit_file_id_mesg.hpp"
#include "fit_file_creator_mesg.hpp"
#include "fit_timestamp_correlation_mesg.hpp"
#include "fit_software_mesg.hpp"
#include "fit_slave_device_mesg.hpp"
#include "fit_capabilities_mesg.hpp"
#include "fit_file_capabilities_mesg.hpp"
#include "fit_mesg_capabilities_mesg.hpp"
#include "fit_field_capabilities_mesg.hpp"
#include "fit_device_settings_mesg.hpp"
#include "fit_user_profile_mesg.hpp"
#include "fit_hrm_profile_mesg.hpp"
#include "fit_sdm_profile_mesg.hpp"
#include "fit_bike_profile_mesg.hpp"
#include "fit_connectivity_mesg.hpp"
#include "fit_watchface_settings_mesg.hpp"
#include "fit_ohr_settings_mesg.hpp"
#include "fit_zones_target_mesg.hpp"
#include "fit_sport_mesg.hpp"
#include "fit_hr_zone_mesg.hpp"
#include "fit_speed_zone_mesg.hpp"
#include "fit_cadence_zone_mesg.hpp"
#include "fit_power_zone_mesg.hpp"
#include "fit_met_zone_mesg.hpp"
#include "fit_dive_settings_mesg.hpp"
#include "fit_dive_alarm_mesg.hpp"
#include "fit_dive_gas_mesg.hpp"
#include "fit_goal_mesg.hpp"
#include "fit_activity_mesg.hpp"
#include "fit_session_mesg.hpp"
#include "fit_lap_mesg.hpp"
#include "fit_length_mesg.hpp"
#include "fit_record_mesg.hpp"
#include "fit_event_mesg.hpp"
#include "fit_device_info_mesg.hpp"
#include "fit_training_file_mesg.hpp"
#include "fit_weather_conditions_mesg.hpp"
#include "fit_weather_alert_mesg.hpp"
#include "fit_gps_metadata_mesg.hpp"
#include "fit_camera_event_mesg.hpp"
#include "fit_gyroscope_data_mesg.hpp"
#include "fit_accelerometer_data_mesg.hpp"
#include "fit_magnetometer_data_mesg.hpp"
#include "fit_barometer_data_mesg.hpp"
#include "fit_three_d_sensor_calibration_mesg.hpp"
#include "fit_one_d_sensor_calibration_mesg.hpp"
#include "fit_video_frame_mesg.hpp"
#include "fit_obdii_data_mesg.hpp"
#include "fit_nmea_sentence_mesg.hpp"
#include "fit_aviation_attitude_mesg.hpp"
#include "fit_video_mesg.hpp"
#include "fit_video_title_mesg.hpp"
#include "fit_video_description_mesg.hpp"
#include "fit_video_clip_mesg.hpp"
#include "fit_set_mesg.hpp"
#include "fit_jump_mesg.hpp"
#include "fit_climb_pro_mesg.hpp"
#include "fit_field_description_mesg.hpp"
#include "fit_developer_data_id_mesg.hpp"
#include "fit_course_mesg.hpp"
#include "fit_course_point_mesg.hpp"
#include "fit_segment_id_mesg.hpp"
#include "fit_segment_leaderboard_entry_mesg.hpp"
#include "fit_segment_point_mesg.hpp"
#include "fit_segment_lap_mesg.hpp"
#include "fit_segment_file_mesg.hpp"
#include "fit_workout_mesg.hpp"
#include "fit_workout_session_mesg.hpp"
#include "fit_workout_step_mesg.hpp"
#include "fit_exercise_title_mesg.hpp"
#include "fit_schedule_mesg.hpp"
#include "fit_totals_mesg.hpp"
#include "fit_weight_scale_mesg.hpp"
#include "fit_blood_pressure_mesg.hpp"
#include "fit_monitoring_info_mesg.hpp"
#include "fit_monitoring_mesg.hpp"
#include "fit_hr_mesg.hpp"
#include "fit_stress_level_mesg.hpp"
#include "fit_memo_glob_mesg.hpp"
#include "fit_ant_channel_id_mesg.hpp"
#include "fit_ant_rx_mesg.hpp"
#include "fit_ant_tx_mesg.hpp"
#include "fit_exd_screen_configuration_mesg.hpp"
#include "fit_exd_data_field_configuration_mesg.hpp"
#include "fit_exd_data_concept_configuration_mesg.hpp"
#include "fit_dive_summary_mesg.hpp"
#include "fit_hrv_mesg.hpp"
#include "fit_pad_mesg.hpp"
#include "fit_srm_record_mesg.hpp"
#include "fit_srm_comment_mesg.hpp"
#include "fit_srm_user_profile_mesg.hpp"
#include "fit_srm_bike_profile_mesg.hpp"
#include "fit_srm_wifi_profile_mesg.hpp"
#include "fit_srm_display_profile_mesg.hpp"
#include "fit_srm_widget_profile_mesg.hpp"
#include "fit_srm_device_settings_mesg.hpp"
#include "fit_tbd_ff0a_mesg.hpp"
#include "fit_tbd_ff0b_mesg.hpp"
#include "fit_srm_totals_mesg.hpp"
#include "fit_srm_session_mesg.hpp"
#include "fit_srm_compatibility_mesg.hpp"
#include "fit_srm_indoor_settings_mesg.hpp"
#include "fit_srm_indoor_gear_offset_mesg.hpp"
#include "fit_srm_workout_step_mesg.hpp"
#include "fit_srm_workout_info_mesg.hpp"
#include "fit_srm_workout_interval_mesg.hpp"
#include "fit_srm_gateway_mesg.hpp"
#include "fit_srm_gateway_credentials_mesg.hpp"
#include "fit_srm_gateway_token_mesg.hpp"
#include "fit_srm_network_streaming_mesg.hpp"
#include "fit_srm_altitude_offset_mesg.hpp"
#include "fit_srm_summary_db_mesg.hpp"
#include "fit_srm_ftp_db_item_mesg.hpp"
#include "fit_srm_auto_ftp_info_mesg.hpp"
#include "fit_srm_gps_altitude_point_mesg.hpp"
#include "fit_srm_torque_mesg.hpp"
#include "fit_srm_wo_compatibility_mesg.hpp"

namespace fit
{

Mesg Factory::CreateMesg(Mesg mesg)
{
    switch (mesg.GetNum())
    {
        
        case FIT_MESG_NUM_FILE_ID:
            return FileIdMesg(mesg);
        
        case FIT_MESG_NUM_FILE_CREATOR:
            return FileCreatorMesg(mesg);
        
        case FIT_MESG_NUM_TIMESTAMP_CORRELATION:
            return TimestampCorrelationMesg(mesg);
        
        case FIT_MESG_NUM_SOFTWARE:
            return SoftwareMesg(mesg);
        
        case FIT_MESG_NUM_SLAVE_DEVICE:
            return SlaveDeviceMesg(mesg);
        
        case FIT_MESG_NUM_CAPABILITIES:
            return CapabilitiesMesg(mesg);
        
        case FIT_MESG_NUM_FILE_CAPABILITIES:
            return FileCapabilitiesMesg(mesg);
        
        case FIT_MESG_NUM_MESG_CAPABILITIES:
            return MesgCapabilitiesMesg(mesg);
        
        case FIT_MESG_NUM_FIELD_CAPABILITIES:
            return FieldCapabilitiesMesg(mesg);
        
        case FIT_MESG_NUM_DEVICE_SETTINGS:
            return DeviceSettingsMesg(mesg);
        
        case FIT_MESG_NUM_USER_PROFILE:
            return UserProfileMesg(mesg);
        
        case FIT_MESG_NUM_HRM_PROFILE:
            return HrmProfileMesg(mesg);
        
        case FIT_MESG_NUM_SDM_PROFILE:
            return SdmProfileMesg(mesg);
        
        case FIT_MESG_NUM_BIKE_PROFILE:
            return BikeProfileMesg(mesg);
        
        case FIT_MESG_NUM_CONNECTIVITY:
            return ConnectivityMesg(mesg);
        
        case FIT_MESG_NUM_WATCHFACE_SETTINGS:
            return WatchfaceSettingsMesg(mesg);
        
        case FIT_MESG_NUM_OHR_SETTINGS:
            return OhrSettingsMesg(mesg);
        
        case FIT_MESG_NUM_ZONES_TARGET:
            return ZonesTargetMesg(mesg);
        
        case FIT_MESG_NUM_SPORT:
            return SportMesg(mesg);
        
        case FIT_MESG_NUM_HR_ZONE:
            return HrZoneMesg(mesg);
        
        case FIT_MESG_NUM_SPEED_ZONE:
            return SpeedZoneMesg(mesg);
        
        case FIT_MESG_NUM_CADENCE_ZONE:
            return CadenceZoneMesg(mesg);
        
        case FIT_MESG_NUM_POWER_ZONE:
            return PowerZoneMesg(mesg);
        
        case FIT_MESG_NUM_MET_ZONE:
            return MetZoneMesg(mesg);
        
        case FIT_MESG_NUM_DIVE_SETTINGS:
            return DiveSettingsMesg(mesg);
        
        case FIT_MESG_NUM_DIVE_ALARM:
            return DiveAlarmMesg(mesg);
        
        case FIT_MESG_NUM_DIVE_GAS:
            return DiveGasMesg(mesg);
        
        case FIT_MESG_NUM_GOAL:
            return GoalMesg(mesg);
        
        case FIT_MESG_NUM_ACTIVITY:
            return ActivityMesg(mesg);
        
        case FIT_MESG_NUM_SESSION:
            return SessionMesg(mesg);
        
        case FIT_MESG_NUM_LAP:
            return LapMesg(mesg);
        
        case FIT_MESG_NUM_LENGTH:
            return LengthMesg(mesg);
        
        case FIT_MESG_NUM_RECORD:
            return RecordMesg(mesg);
        
        case FIT_MESG_NUM_EVENT:
            return EventMesg(mesg);
        
        case FIT_MESG_NUM_DEVICE_INFO:
            return DeviceInfoMesg(mesg);
        
        case FIT_MESG_NUM_TRAINING_FILE:
            return TrainingFileMesg(mesg);
        
        case FIT_MESG_NUM_WEATHER_CONDITIONS:
            return WeatherConditionsMesg(mesg);
        
        case FIT_MESG_NUM_WEATHER_ALERT:
            return WeatherAlertMesg(mesg);
        
        case FIT_MESG_NUM_GPS_METADATA:
            return GpsMetadataMesg(mesg);
        
        case FIT_MESG_NUM_CAMERA_EVENT:
            return CameraEventMesg(mesg);
        
        case FIT_MESG_NUM_GYROSCOPE_DATA:
            return GyroscopeDataMesg(mesg);
        
        case FIT_MESG_NUM_ACCELEROMETER_DATA:
            return AccelerometerDataMesg(mesg);
        
        case FIT_MESG_NUM_MAGNETOMETER_DATA:
            return MagnetometerDataMesg(mesg);
        
        case FIT_MESG_NUM_BAROMETER_DATA:
            return BarometerDataMesg(mesg);
        
        case FIT_MESG_NUM_THREE_D_SENSOR_CALIBRATION:
            return ThreeDSensorCalibrationMesg(mesg);
        
        case FIT_MESG_NUM_ONE_D_SENSOR_CALIBRATION:
            return OneDSensorCalibrationMesg(mesg);
        
        case FIT_MESG_NUM_VIDEO_FRAME:
            return VideoFrameMesg(mesg);
        
        case FIT_MESG_NUM_OBDII_DATA:
            return ObdiiDataMesg(mesg);
        
        case FIT_MESG_NUM_NMEA_SENTENCE:
            return NmeaSentenceMesg(mesg);
        
        case FIT_MESG_NUM_AVIATION_ATTITUDE:
            return AviationAttitudeMesg(mesg);
        
        case FIT_MESG_NUM_VIDEO:
            return VideoMesg(mesg);
        
        case FIT_MESG_NUM_VIDEO_TITLE:
            return VideoTitleMesg(mesg);
        
        case FIT_MESG_NUM_VIDEO_DESCRIPTION:
            return VideoDescriptionMesg(mesg);
        
        case FIT_MESG_NUM_VIDEO_CLIP:
            return VideoClipMesg(mesg);
        
        case FIT_MESG_NUM_SET:
            return SetMesg(mesg);
        
        case FIT_MESG_NUM_JUMP:
            return JumpMesg(mesg);
        
        case FIT_MESG_NUM_CLIMB_PRO:
            return ClimbProMesg(mesg);
        
        case FIT_MESG_NUM_FIELD_DESCRIPTION:
            return FieldDescriptionMesg(mesg);
        
        case FIT_MESG_NUM_DEVELOPER_DATA_ID:
            return DeveloperDataIdMesg(mesg);
        
        case FIT_MESG_NUM_COURSE:
            return CourseMesg(mesg);
        
        case FIT_MESG_NUM_COURSE_POINT:
            return CoursePointMesg(mesg);
        
        case FIT_MESG_NUM_SEGMENT_ID:
            return SegmentIdMesg(mesg);
        
        case FIT_MESG_NUM_SEGMENT_LEADERBOARD_ENTRY:
            return SegmentLeaderboardEntryMesg(mesg);
        
        case FIT_MESG_NUM_SEGMENT_POINT:
            return SegmentPointMesg(mesg);
        
        case FIT_MESG_NUM_SEGMENT_LAP:
            return SegmentLapMesg(mesg);
        
        case FIT_MESG_NUM_SEGMENT_FILE:
            return SegmentFileMesg(mesg);
        
        case FIT_MESG_NUM_WORKOUT:
            return WorkoutMesg(mesg);
        
        case FIT_MESG_NUM_WORKOUT_SESSION:
            return WorkoutSessionMesg(mesg);
        
        case FIT_MESG_NUM_WORKOUT_STEP:
            return WorkoutStepMesg(mesg);
        
        case FIT_MESG_NUM_EXERCISE_TITLE:
            return ExerciseTitleMesg(mesg);
        
        case FIT_MESG_NUM_SCHEDULE:
            return ScheduleMesg(mesg);
        
        case FIT_MESG_NUM_TOTALS:
            return TotalsMesg(mesg);
        
        case FIT_MESG_NUM_WEIGHT_SCALE:
            return WeightScaleMesg(mesg);
        
        case FIT_MESG_NUM_BLOOD_PRESSURE:
            return BloodPressureMesg(mesg);
        
        case FIT_MESG_NUM_MONITORING_INFO:
            return MonitoringInfoMesg(mesg);
        
        case FIT_MESG_NUM_MONITORING:
            return MonitoringMesg(mesg);
        
        case FIT_MESG_NUM_HR:
            return HrMesg(mesg);
        
        case FIT_MESG_NUM_STRESS_LEVEL:
            return StressLevelMesg(mesg);
        
        case FIT_MESG_NUM_MEMO_GLOB:
            return MemoGlobMesg(mesg);
        
        case FIT_MESG_NUM_ANT_CHANNEL_ID:
            return AntChannelIdMesg(mesg);
        
        case FIT_MESG_NUM_ANT_RX:
            return AntRxMesg(mesg);
        
        case FIT_MESG_NUM_ANT_TX:
            return AntTxMesg(mesg);
        
        case FIT_MESG_NUM_EXD_SCREEN_CONFIGURATION:
            return ExdScreenConfigurationMesg(mesg);
        
        case FIT_MESG_NUM_EXD_DATA_FIELD_CONFIGURATION:
            return ExdDataFieldConfigurationMesg(mesg);
        
        case FIT_MESG_NUM_EXD_DATA_CONCEPT_CONFIGURATION:
            return ExdDataConceptConfigurationMesg(mesg);
        
        case FIT_MESG_NUM_DIVE_SUMMARY:
            return DiveSummaryMesg(mesg);
        
        case FIT_MESG_NUM_HRV:
            return HrvMesg(mesg);
        
        case FIT_MESG_NUM_PAD:
            return PadMesg(mesg);
        
        case FIT_MESG_NUM_SRM_RECORD:
            return SrmRecordMesg(mesg);
        
        case FIT_MESG_NUM_SRM_COMMENT:
            return SrmCommentMesg(mesg);
        
        case FIT_MESG_NUM_SRM_USER_PROFILE:
            return SrmUserProfileMesg(mesg);
        
        case FIT_MESG_NUM_SRM_BIKE_PROFILE:
            return SrmBikeProfileMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WIFI_PROFILE:
            return SrmWifiProfileMesg(mesg);
        
        case FIT_MESG_NUM_SRM_DISPLAY_PROFILE:
            return SrmDisplayProfileMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WIDGET_PROFILE:
            return SrmWidgetProfileMesg(mesg);
        
        case FIT_MESG_NUM_SRM_DEVICE_SETTINGS:
            return SrmDeviceSettingsMesg(mesg);
        
        case FIT_MESG_NUM_TBD_FF0A:
            return TbdFf0aMesg(mesg);
        
        case FIT_MESG_NUM_TBD_FF0B:
            return TbdFf0bMesg(mesg);
        
        case FIT_MESG_NUM_SRM_TOTALS:
            return SrmTotalsMesg(mesg);
        
        case FIT_MESG_NUM_SRM_SESSION:
            return SrmSessionMesg(mesg);
        
        case FIT_MESG_NUM_SRM_COMPATIBILITY:
            return SrmCompatibilityMesg(mesg);
        
        case FIT_MESG_NUM_SRM_INDOOR_SETTINGS:
            return SrmIndoorSettingsMesg(mesg);
        
        case FIT_MESG_NUM_SRM_INDOOR_GEAR_OFFSET:
            return SrmIndoorGearOffsetMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WORKOUT_STEP:
            return SrmWorkoutStepMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WORKOUT_INFO:
            return SrmWorkoutInfoMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WORKOUT_INTERVAL:
            return SrmWorkoutIntervalMesg(mesg);
        
        case FIT_MESG_NUM_SRM_GATEWAY:
            return SrmGatewayMesg(mesg);
        
        case FIT_MESG_NUM_SRM_GATEWAY_CREDENTIALS:
            return SrmGatewayCredentialsMesg(mesg);
        
        case FIT_MESG_NUM_SRM_GATEWAY_TOKEN:
            return SrmGatewayTokenMesg(mesg);
        
        case FIT_MESG_NUM_SRM_NETWORK_STREAMING:
            return SrmNetworkStreamingMesg(mesg);
        
        case FIT_MESG_NUM_SRM_ALTITUDE_OFFSET:
            return SrmAltitudeOffsetMesg(mesg);
        
        case FIT_MESG_NUM_SRM_SUMMARY_DB:
            return SrmSummaryDbMesg(mesg);
        
        case FIT_MESG_NUM_SRM_FTP_DB_ITEM:
            return SrmFtpDbItemMesg(mesg);
        
        case FIT_MESG_NUM_SRM_AUTO_FTP_INFO:
            return SrmAutoFtpInfoMesg(mesg);
        
        case FIT_MESG_NUM_SRM_GPS_ALTITUDE_POINT:
            return SrmGpsAltitudePointMesg(mesg);
        
        case FIT_MESG_NUM_SRM_TORQUE:
            return SrmTorqueMesg(mesg);
        
        case FIT_MESG_NUM_SRM_WO_COMPATIBILITY:
            return SrmWoCompatibilityMesg(mesg);
        
        default:
        break;
    }
    return mesg;
}


} // namespace fit

