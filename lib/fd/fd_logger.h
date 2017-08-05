#ifndef __FD_LOGGER_H__
#define __FD_LOGGER_H__

#include "core_errno.h"

#include "freeDiameter/freeDiameter-host.h"
#include "freeDiameter/libfdcore.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(int) fd_logger_init();
CORE_DECLARE(void) fd_logger_final();

CORE_DECLARE(int) fd_logger_stats_start();

typedef void (*fd_logger_user_handler)(
    enum fd_hook_type type, struct msg *msg, struct peer_hdr *peer, 
    void *other, struct fd_hook_permsgdata *pmd, void *regdata);

CORE_DECLARE(void) fd_logger_register(fd_logger_user_handler instance);
CORE_DECLARE(void) fd_logger_unregister();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ! __FD_LOGGER_H__ */
