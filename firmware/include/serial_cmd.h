/**
 * YOKO — Serial command interface
 * Line-based command parser for open/close/home/status/clear-fault control.
 */

#ifndef SERIAL_CMD_H
#define SERIAL_CMD_H

void serial_cmd_init(void);

/* Call every loop tick to poll and process incoming serial commands. */
void serial_cmd_update(void);

#endif /* SERIAL_CMD_H */
