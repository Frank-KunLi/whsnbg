/*
* Copyright (c) 2013-2015 Vladimir Alemasov
* All rights reserved
*
* This program and the accompanying materials are distributed under 
* the terms of GNU General Public License version 2 
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef MSG_MQTT_MYSQL_H_
#define MSG_MQTT_MYSQL_H_

#include "msgs.h"
#include <time.h>		/* time_t, time() */

#ifdef _MSC_VER
#include "stdint_msc.h"	/* uint8_t ... uint64_t */
#else
#include <stdint.h>		/* uint8_t ... uint64_t */
#include <stddef.h>		/* size_t */
#endif

//--------------------------------------------
typedef enum msg_mysql_type
{
	MYSQL_ADD_LONG_DATA,
	MYSQL_ADD_FLOAT_DATA,
	MYSQL_ADD_UTF8STR_DATA,
	MYSQL_UPDATE_SENSOR_IP,
	MYSQL_UPDATE_SENSOR_PARAM,
	MYSQL_UPDATE_SENSOR_SLEEPTIMEDURATION,
	MYSQL_UPDATE_SENSOR_LOCATION
} msg_mysql_type_t;

//--------------------------------------------
typedef struct msg_mysql_add_long_data
{
	uint32_t sensor_id;
	uint32_t sensor_param;
	time_t timestamp;
	long long_data;
} msg_mysql_add_long_data_t;

typedef struct msg_mysql_add_float_data
{
	uint32_t sensor_id;
	uint32_t sensor_param;
	time_t timestamp;
	float float_data;
} msg_mysql_add_float_data_t;

typedef struct msg_mysql_add_utf8str_data
{
	uint32_t sensor_id;
	uint32_t sensor_param;
	time_t timestamp;
	char *utf8str_data;
} msg_mysql_add_utf8str_data_t;

typedef struct msg_mysql_add_sensor_param
{
	uint32_t sensor_id;
	uint32_t sensor_param;
	char *utf8str_data;
} msg_mysql_add_sensor_param_t;

typedef struct msg_mysql_add_sensor_utf8str
{
	uint32_t sensor_id;
	char *utf8str_data;
} msg_mysql_add_sensor_utf8str_t;

typedef struct msg_mysql_add_sensor_long
{
	uint32_t sensor_id;
	long long_data;
} msg_mysql_add_sensor_long_t;




//--------------------------------------------
typedef struct msg_mqtt_mysql
{
	msg_t msg;
	msg_mysql_type_t type;
	void *msg_mysql;
} msg_mqtt_mysql_t;

//--------------------------------------------
void msg_mqtt_mysql_init(void);
msg_mqtt_mysql_t *msg_mqtt_mysql_new(void);
void msg_mqtt_mysql_add(msg_mqtt_mysql_t *ms);
void msg_mqtt_mysql_remove(msg_mqtt_mysql_t *ms);
msg_mqtt_mysql_t *msg_mqtt_mysql_get_first(void);
#define msg_mqtt_mysql_close() msg_close(a)
void msg_mqtt_mysql_destroy(void);

void msg_mqtt_mysql_add_long_data(uint32_t sensor_id, uint32_t sensor_param, long long_data);
void msg_mqtt_mysql_add_float_data(uint32_t sensor_id, uint32_t sensor_param, float float_data);
void msg_mqtt_mysql_add_utf8str_data(uint32_t sensor_id, uint32_t sensor_param, char *utf8str_data);
void msg_mqtt_mysql_update_sensor_ip(uint32_t sensor_id, char *utf8str_data);
void msg_mqtt_mysql_update_sensor_sleeptimeduration(uint32_t sensor_id, long long_data);
void msg_mqtt_mysql_update_sensor_param(uint32_t sensor_id, uint32_t sensor_param, char *utf8str_data);
void msg_mqtt_mysql_update_sensor_location(uint32_t sensor_id, char *utf8str_data);

#endif /* MSG_MQTT_MYSQL_H_ */
