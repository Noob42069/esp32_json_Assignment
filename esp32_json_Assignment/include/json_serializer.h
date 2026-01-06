#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>

/* -------- Data Models -------- */

typedef struct {
    const char *timestamp;
    const char *meter_datetime;
    float total_m3;
    const char *status;
} DataPoint;

typedef struct {
    const char *media;
    const char *meter;
    const char *deviceId;
    const char *unit;
    DataPoint *data;
    int data_count;
} DeviceReading;

typedef struct {
    int device_count;
    DeviceReading *readings;
} Values;

typedef struct {
    const char *gatewayId;
    const char *date;
    const char *deviceType;
    int interval_minutes;
    int total_readings;
    Values values;
} GatewayPacket;

/* -------- API -------- */

/*
 * Serializes GatewayPacket into JSON.
 * Returns:
 *  >=0 : number of bytes written
 *  -1  : invalid arguments
 *  -2  : buffer too small
 */
int serialize_to_json(const GatewayPacket *pkt,
                      char *buffer,
                      size_t buffer_size);

#endif
