/*
 *	Logger Library by Parra Studios
 *	Copyright (C) 2016 - 2024 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	A generic logger library providing application execution reports.
 *
 */

#ifndef LOG_POLICY_FORMAT_BINARY_H
#define LOG_POLICY_FORMAT_BINARY_H 1

/* -- Headers -- */

#include <log/log_api.h>

#include <log/log_policy.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -- Methods -- */

LOG_API log_policy_interface log_policy_format_binary_interface(void);

#ifdef __cplusplus
}
#endif

#endif /* LOG_POLICY_FORMAT_BINARY_H */
