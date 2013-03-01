/**
 * @file
 * @brief
 *
 * @date 06.01.11
 * @author Anton Bondarev
 */

#include <assert.h>

#include <asm/io.h>
#include <asm/regs.h>
#include <asm/traps.h>
#include <asm/linkage.h>
#include <drivers/irqctrl.h>
#include <drivers/i8259.h>
#include <hal/reg.h>
#include <kernel/irq.h>

fastcall void irq_handler(pt_regs_t *regs) {
	assert(!critical_inside(CRITICAL_IRQ_LOCK));

	critical_enter(CRITICAL_IRQ_HANDLER);
	{
		int irq = regs->trapno - 0x20;

		ipl_enable();

		irq_dispatch(irq);

		i8259_send_eoi(irq);

		ipl_disable();
	}
	critical_leave(CRITICAL_IRQ_HANDLER);
	critical_dispatch_pending();
}
