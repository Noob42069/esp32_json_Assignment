#include "json_serializer.h"
#include <stdio.h>

int serialize_to_json(const GatewayPacket *pkt,
                      char *buffer,
                      size_t buffer_size)
{
    if (!pkt || !buffer || buffer_size == 0)
        return -1;

    int written = snprintf(
        buffer,
        buffer_size,
        "[{"
        "\"gatewayId\":\"%s\","
        "\"date\":\"%s\","
        "\"deviceType\":\"%s\","
        "\"interval_minutes\":%d,"
        "\"total_readings\":%d,"
        "\"values\":{"
            "\"device_count\":%d,"
            "\"readings\":[{"
                "\"media\":\"%s\","
                "\"meter\":\"%s\","
                "\"deviceId\":\"%s\","
                "\"unit\":\"%s\","
                "\"data\":[{"
                    "\"timestamp\":\"%s\","
                    "\"meter_datetime\":\"%s\","
                    "\"total_m3\":%.3f,"
                    "\"status\":\"%s\""
                "}]"
            "}]"
        "}"
        "}]",

        pkt->gatewayId,
        pkt->date,
        pkt->deviceType,
        pkt->interval_minutes,
        pkt->total_readings,
        pkt->values.device_count,
        pkt->values.readings[0].media,
        pkt->values.readings[0].meter,
        pkt->values.readings[0].deviceId,
        pkt->values.readings[0].unit,
        pkt->values.readings[0].data[0].timestamp,
        pkt->values.readings[0].data[0].meter_datetime,
        pkt->values.readings[0].data[0].total_m3,
        pkt->values.readings[0].data[0].status
    );

    if (written < 0 || (size_t)written >= buffer_size)
        return -2;

    return written;
}
