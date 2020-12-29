/*
 * Copyright (C) 2020 Samsung Electronics. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/gpio.h>

#include "et5xx.h"

int et5xx_io_burst_write_register(struct et5xx_data *etspi,
		struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	struct spi_transfer xfer = {
		.tx_buf = etspi->buf,
		.len = ioc->len + 1,
	};

	if (ioc->len <= 0 || ioc->len + 2 > etspi->bufsiz) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	memset(etspi->buf, 0, ioc->len + 1);
	*etspi->buf = OP_REG_W_C;
	if (copy_from_user(etspi->buf + 1,
			(const u8 __user *) (uintptr_t) ioc->tx_buf,
			ioc->len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		goto end;
	}
	pr_debug("tx_buf = %p op = %x reg = %x, len = %d\n",
			ioc->tx_buf, *etspi->buf, *(etspi->buf + 1), xfer.len);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval < 0) {
		pr_err("error retval = %d\n", retval);
		goto end;
	}
end:
	return retval;
#endif
}

int et5xx_io_burst_write_register_backward(struct et5xx_data *etspi,
		struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	struct spi_transfer xfer = {
		.tx_buf = etspi->buf,
		.len = ioc->len + 1,
	};

	if (ioc->len <= 0 || ioc->len + 2 > etspi->bufsiz) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	memset(etspi->buf, 0, ioc->len + 1);
	*etspi->buf = OP_REG_W_C_BW;
	if (copy_from_user(etspi->buf + 1,
		(const u8 __user *) (uintptr_t)ioc->tx_buf, ioc->len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		goto end;
	}
	pr_debug("tx_buf = %p op = %x reg = %x, len = %d\n",
		ioc->tx_buf, *etspi->buf, *(etspi->buf + 1), xfer.len);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval < 0) {
		pr_err("error retval = %d\n", retval);
		goto end;
	}
end:
	return retval;
#endif
}

int et5xx_io_burst_read_register(struct et5xx_data *etspi,
		struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	struct spi_transfer xfer = {
		.tx_buf = etspi->buf,
		.rx_buf = etspi->buf,
		.len = ioc->len + 2,
	};

	if (ioc->len <= 0 || ioc->len + 2 > etspi->bufsiz) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	memset(etspi->buf, 0, xfer.len);
	*etspi->buf = OP_REG_R_C;
	if (copy_from_user(etspi->buf + 1,
			(const u8 __user *) (uintptr_t) ioc->tx_buf, 1)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		goto end;
	}
	pr_debug("tx_buf = %p op = %x reg = %x, len = %d\n",
			ioc->tx_buf, *etspi->buf, *(etspi->buf + 1), xfer.len);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval < 0) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	if (copy_to_user((u8 __user *) (uintptr_t)ioc->rx_buf, etspi->buf + 2,
				ioc->len)) {
		retval = -EFAULT;
		pr_err("buffer copy_to_user fail retval\n");
		goto end;
	}
end:
	return retval;
#endif
}

int et5xx_io_burst_read_register_backward(struct et5xx_data *etspi,
		struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	struct spi_transfer xfer = {
		.tx_buf = etspi->buf,
		.rx_buf = etspi->buf,
		.len = ioc->len + 2,
	};

	if (ioc->len <= 0 || ioc->len + 2 > etspi->bufsiz) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	memset(etspi->buf, 0, xfer.len);
	*etspi->buf = OP_REG_R_C_BW;
	if (copy_from_user(etspi->buf + 1,
			(const u8 __user *) (uintptr_t)ioc->tx_buf, 1)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		goto end;
	}
	pr_debug("tx_buf = %p op = %x reg = %x, len = %d\n",
			ioc->tx_buf, *etspi->buf, *(etspi->buf + 1), xfer.len);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval < 0) {
		retval = -ENOMEM;
		pr_err("error retval = %d\n", retval);
		goto end;
	}

	if (copy_to_user((u8 __user *) (uintptr_t)ioc->rx_buf, etspi->buf + 2,
			ioc->len)) {
		retval = -EFAULT;
		pr_err("buffer copy_to_user fail retval\n");
		goto end;
	}
end:
	return retval;
#endif
}

int et5xx_io_read_registerex(struct et5xx_data *etspi, u8 *addr, u8 *buf,
		u32 len)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	struct spi_transfer xfer = {
		.tx_buf = etspi->buf,
		.rx_buf = etspi->buf,
		.len = len + 2,
	};

	if (len <= 0 || len + 2 > etspi->bufsiz) {
		retval = -ENOMEM;
		pr_err("error retval = %d", retval);
		goto end;
	}

	memset(etspi->buf, 0, xfer.len);
	*etspi->buf = OP_REG_R;

	if (copy_from_user(etspi->buf + 1, (const u8 __user *) (uintptr_t) addr
			, 1)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		goto end;
	}

	pr_debug("addr = %p op = %x reg = %x len = %d tx = %p, rx = %p",
			addr, etspi->buf[0], etspi->buf[1], len,
			xfer.tx_buf, xfer.rx_buf);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("read data error retval = %d\n", retval);
		goto end;
	}


	if (copy_to_user((u8 __user *) (uintptr_t) buf, etspi->buf + 2, len)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
		goto end;
	}
end:
	return retval;
#endif
}

/* Read io register */
int et5xx_io_read_register(struct et5xx_data *etspi, u8 *addr, u8 *buf)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	struct spi_message m;
	int read_len = 1;

	u8 tx[] = {OP_REG_R, 0x00, 0x00};
	u8 val, addrval;
	u8 rx[] = {0xFF, 0x00, 0x00};

	struct spi_transfer xfer = {
		.tx_buf = tx,
		.rx_buf = rx,
		.len = 3,
	};

	if (copy_from_user(&addrval, (const u8 __user *) (uintptr_t) addr
		, read_len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		return retval;
	}

	tx[1] = addrval;

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("read data error retval = %d\n", retval);
		return retval;
	}

	val = rx[2];

	pr_debug("len = %d addr = %p val = %x\n",
			read_len, addr, val);

	if (copy_to_user((u8 __user *) (uintptr_t) buf, &val, read_len)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
		return retval;
	}

	return retval;
#endif
}

/* Write data to register */
int et5xx_io_write_register(struct et5xx_data *etspi, u8 *buf)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval = 0;
	int write_len = 2;
	struct spi_message m;

	u8 tx[] = {OP_REG_W, 0x00, 0x00};
	u8 val[3];

	struct spi_transfer xfer = {
		.tx_buf = tx,
		.len = 3,
	};

	if (copy_from_user(val, (const u8 __user *) (uintptr_t) buf,
			write_len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		return retval;
	}

	pr_debug("write_len = %d addr = %x data = %x\n",
			write_len, val[0], val[1]);

	tx[1] = val[0];
	tx[2] = val[1];

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("read data error retval = %d\n", retval);
		return retval;
	}

	return retval;
#endif
}

int et5xx_write_register(struct et5xx_data *etspi, u8 addr, u8 buf)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;

	u8 tx[] = {OP_REG_W, addr, buf};

	struct spi_transfer xfer = {
		.tx_buf = tx,
		.rx_buf	= NULL,
		.len = 3,
	};

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0) {
		pr_debug("address = %x\n", addr);
	} else {
		pr_err("read data error retval = %d\n", retval);
	}

	return retval;
#endif
}
int et5xx_read_register(struct et5xx_data *etspi, u8 addr, u8 *buf)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;

	static u8 read_value[] = {OP_REG_R, 0x00, 0x00};
	static u8 result[] = {0xFF, 0xFF, 0xFF};

	struct spi_transfer xfer = {
		.tx_buf = NULL,
		.rx_buf	= result,
		.len = 3,
	};

	read_value[1] = addr;
	xfer.tx_buf = read_value;

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0) {
		*buf = result[2];
		pr_debug("address = %x result = %x %x\n", addr, result[1], result[2]);
	} else {
		pr_err("read data error retval = %d\n", retval);
	}

	return retval;
#endif
}

int et5xx_io_nvm_read(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;

	u8 addr/* nvm logical address */, buf[] = {OP_NVM_RE, 0x00};

	struct spi_transfer xfer = {
		.tx_buf = buf,
		.rx_buf	= NULL,
		.len = 2,
	};

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0)
		pr_debug("nvm enabled\n");
	else
		pr_err("nvm enable error retval = %d\n", retval);

	usleep_range(10, 50);

	if (copy_from_user(&addr, (const u8 __user *) (uintptr_t) ioc->tx_buf
		, 1)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		return retval;
	}

	etspi->buf[0] = OP_NVM_ON_R;

	pr_debug("logical addr(%x) len(%d)\n", addr, ioc->len);
	if ((addr + ioc->len) > MAX_NVM_LEN)
		return -EINVAL;

	/* transfer to nvm physical address*/
	etspi->buf[1] = ((addr % 2) ? (addr - 1) : addr) / 2;
	/* thansfer to nvm physical length */
	xfer.len = ((ioc->len % 2) ? ioc->len + 1 :
			(addr % 2 ? ioc->len + 2 : ioc->len)) + 3;
	if (xfer.len >= LARGE_SPI_TRANSFER_BUFFER) {
		if ((xfer.len) % DIVISION_OF_IMAGE != 0)
			xfer.len = xfer.len + (DIVISION_OF_IMAGE -
					(xfer.len % DIVISION_OF_IMAGE));
	}
	xfer.tx_buf = xfer.rx_buf = etspi->buf;

	pr_debug("nvm read addr(%d) len(%d) xfer.rx_buf(%p), etspi->buf(%p)\n",
			etspi->buf[1], xfer.len, xfer.rx_buf, etspi->buf);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("error retval = %d\n", retval);
		return retval;
	}

	if (copy_to_user((u8 __user *) (uintptr_t) ioc->rx_buf, xfer.rx_buf + 3
			, ioc->len)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
		return retval;
	}

	return retval;
#endif
}

int et5xx_io_nvm_write(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval, i, j, len/* physical nvm length */;
	struct spi_message m;
	u8 *bufw = NULL;
	u8 buf[MAX_NVM_LEN + 1] = {OP_NVM_WE, 0x00};
	u8 addr/* nvm physical addr */;

	struct spi_transfer xfer = {
		.tx_buf = buf,
		.rx_buf	= NULL,
		.len = 2,
	};

	if (ioc->len > (MAX_NVM_LEN + 1))
		return -EINVAL;

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0)
		pr_debug("nvm enabled\n");
	else
		pr_err("nvm enable error retval = %d\n", retval);

	usleep_range(10, 50);

	pr_debug("buf(%p) tx_buf(%p) len(%d)\n", buf,
			ioc->tx_buf, ioc->len);
	if (copy_from_user(buf, (const u8 __user *) (uintptr_t) ioc->tx_buf,
			ioc->len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		return retval;
	}

	if ((buf[0] + (ioc->len - 1)) > MAX_NVM_LEN)
		return -EINVAL;
	if ((buf[0] % 2) || ((ioc->len - 1) % 2)) {
		/* TODO: add non alignment handling */
		pr_err("can't handle address alignment issue. %d %d\n",
				buf[0], ioc->len);
		return -EINVAL;
	}

	bufw = kmalloc(NVM_WRITE_LENGTH, GFP_KERNEL);
	/*TODO: need to dynamic assign nvm length*/
	if (bufw == NULL) {
		retval = -ENOMEM;
		pr_err("bufw kmalloc error\n");
		return retval;
	}
	xfer.tx_buf = xfer.rx_buf = bufw;
	xfer.len = NVM_WRITE_LENGTH;

	len = (ioc->len - 1) / 2;
	pr_debug("nvm write addr(%d) len(%d) xfer.tx_buf(%p), etspi->buf(%p)\n",
			buf[0], len, xfer.tx_buf, etspi->buf);
	for (i = 0, addr = buf[0] / 2/* thansfer to nvm physical length */;
			i < len; i++) {
		bufw[0] = OP_NVM_ON_W;
		bufw[1] = addr++;
		bufw[2] = buf[i * 2 + 1];
		bufw[3] = buf[i * 2 + 2];
		memset(bufw + 4, 1, NVM_WRITE_LENGTH - 4);

		pr_debug("write transaction (%d): %x %x %x %x\n",
				i, bufw[0], bufw[1], bufw[2], bufw[3]);
		spi_message_init(&m);
		spi_message_add_tail(&xfer, &m);
		retval = spi_sync(etspi->spi, &m);
		if (retval < 0) {
			pr_err("error retval = %d\n", retval);
			goto end;
		}
		for (j = 0; j < NVM_WRITE_LENGTH - 4; j++) {
			if (bufw[4 + j] == 0) {
				pr_debug("nvm write ready(%d)\n", j);
				break;
			}
			if (j == NVM_WRITE_LENGTH - 5) {
				pr_err("nvm write fail(timeout)\n");
				retval = -EIO;
				goto end;
			}
		}
	}
end:
	kfree(bufw);
	return retval;
#endif
}

int et5xx_nvm_read(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;

	u8 addr/* nvm logical address */, buf[] = {OP_NVM_RE, 0x00};

	struct spi_transfer xfer = {
		.tx_buf = buf,
		.rx_buf	= NULL,
		.len = 2,
	};

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0)
		pr_debug("nvm enabled\n");
	else
		pr_err("nvm enable error retval = %d\n", retval);

	usleep_range(10, 50);

	addr = ioc->tx_buf[0];

	etspi->buf[0] = OP_NVM_ON_R;

	pr_debug("logical addr(%x) len(%d)\n", addr, ioc->len);
	if ((addr + ioc->len) > MAX_NVM_LEN)
		return -EINVAL;

	/* transfer to nvm physical address*/
	etspi->buf[1] = ((addr % 2) ? (addr - 1) : addr) / 2;
	/* thansfer to nvm physical length */
	xfer.len = ((ioc->len % 2) ? ioc->len + 1 :
			(addr % 2 ? ioc->len + 2 : ioc->len)) + 3;
	if (xfer.len >= LARGE_SPI_TRANSFER_BUFFER) {
		if ((xfer.len) % DIVISION_OF_IMAGE != 0)
			xfer.len = xfer.len + (DIVISION_OF_IMAGE -
					(xfer.len % DIVISION_OF_IMAGE));
	}
	xfer.tx_buf = xfer.rx_buf = etspi->buf;

	pr_debug("nvm read addr(%d) len(%d) xfer.rx_buf(%p), etspi->buf(%p)\n",
			etspi->buf[1], xfer.len, xfer.rx_buf, etspi->buf);
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("error retval = %d\n", retval);
		return retval;
	}

	if (memcpy((u8 __user *) (uintptr_t) ioc->rx_buf, xfer.rx_buf + 3,
			ioc->len)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
		return retval;
	}

	return retval;
#endif
}
int et5xx_io_nvm_writeex(struct et5xx_data *etspi,
		struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval, i, j, len/* physical nvm length */, wlen;
	struct spi_message m;
	u8 *bufw = NULL;
	u8 bufr[MAX_NVM_LEN + 3];
	u8 buf[MAX_NVM_LEN + 3] = {OP_NVM_WE, 0x00};
	u8 addr/* nvm physical addr */, *tmp = NULL;
	struct egis_ioc_transfer r;

	struct spi_transfer xfer = {
		.tx_buf = buf,
		.rx_buf	= NULL,
		.len = 2,
	};

	pr_debug("buf(%p) tx_buf(%p) len(%d)\n",
			buf, ioc->tx_buf, ioc->len);
	if (copy_from_user(buf, (const u8 __user *) (uintptr_t) ioc->tx_buf
		, ioc->len)) {
		pr_err("buffer copy_from_user fail\n");
		retval = -EFAULT;
		return retval;
	}

	if ((buf[0] + (ioc->len - 3)) > MAX_NVM_LEN)
		return -EINVAL;
	if ((buf[0] % 2) || ((ioc->len - 3) % 2)) {
		/* address non-alignment handling */
		pr_debug("handle address alignment issue. %d %d\n", buf[0], ioc->len);

		r.tx_buf = r.rx_buf = bufr;
		r.len = ioc->len;
		if (buf[0] % 2) {
			r.tx_buf[0] = buf[0] - 1;
			r.len = ioc->len % 2 ? r.len + 1 : r.len + 2;
		} else {
			if (ioc->len % 2)
				r.len++;
		}
		pr_debug("fixed address alignment issue. %d %d\n", r.tx_buf[0], r.len);
		et5xx_nvm_read(etspi, &r);

		tmp = bufr;
		if (buf[0] % 2)
			tmp++;
		memcpy(tmp, buf, ioc->len);
	}

	buf[0] = OP_NVM_WE;
	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0)
		pr_debug("nvm enabled\n");
	else
		pr_err("nvm enable error retval = %d\n", retval);

	usleep_range(10, 50);

	wlen = *(u16 *)(buf + 1);
	pr_debug("wlen(%d)\n", wlen);
	if (wlen > 8192)
		wlen = 8196;
	bufw = kmalloc(wlen, GFP_KERNEL);
	if (bufw == NULL) {
		retval = -ENOMEM;
		pr_err("bufw kmalloc error\n");
		return retval;
	}
	xfer.tx_buf = xfer.rx_buf = bufw;
	xfer.len = wlen;

	if ((buf[0] % 2) || ((ioc->len - 3) % 2)) {
		memcpy(buf, bufr, r.len);
		ioc->len = r.len;
	}
	len = (ioc->len - 3) / 2;
	pr_debug("nvm write addr(%d) len(%d) xfer.tx_buf(%p), etspi->buf(%p), wlen(%d)\n",
			 buf[0], len, xfer.tx_buf, etspi->buf, wlen);
	for (i = 0, addr = buf[0] / 2/* thansfer to nvm physical length */;
			i < len; i++) {
		bufw[0] = OP_NVM_ON_W;
		bufw[1] = addr++;
		bufw[2] = buf[i * 2 + 3];
		bufw[3] = buf[i * 2 + 4];
		memset(bufw + 4, 1, wlen - 4);

		pr_debug("write transaction (%d): %x %x %x %x\n",
				i, bufw[0], bufw[1], bufw[2], bufw[3]);
		spi_message_init(&m);
		spi_message_add_tail(&xfer, &m);
		retval = spi_sync(etspi->spi, &m);
		if (retval < 0) {
			pr_err("error retval = %d\n", retval);
			goto end;
		}
		for (j = 0; j < wlen - 4; j++) {
			if (bufw[4 + j] == 0) {
				pr_debug("nvm write ready(%d)\n", j);
				break;
			}
			if (j == wlen - 5) {
				pr_err("nvm write fail(timeout)\n");
				retval = -EIO;
				goto end;
			}
		}
	}
end:
	kfree(bufw);
	return retval;
#endif
}

int et5xx_io_nvm_off(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;

	u8 buf[] = {OP_NVM_OFF, 0x00};

	struct spi_transfer xfer = {
		.tx_buf = buf,
		.rx_buf	= NULL,
		.len = 2,
	};

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval == 0)
		pr_debug("nvm disabled\n");
	else
		pr_err("nvm disable error retval = %d\n", retval);

	return retval;
#endif
}
int et5xx_io_vdm_read(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;
	u8 *buf = NULL;

	struct spi_transfer xfer = {
		.tx_buf = NULL,
		.rx_buf = NULL,
		.len = ioc->len + 1,
	};

	if (xfer.len >= LARGE_SPI_TRANSFER_BUFFER) {
		if ((xfer.len) % DIVISION_OF_IMAGE != 0)
			xfer.len = xfer.len + (DIVISION_OF_IMAGE -
					(xfer.len % DIVISION_OF_IMAGE));
	}

	buf = kzalloc(xfer.len, GFP_KERNEL);

	if (buf == NULL)
		return -ENOMEM;

	xfer.tx_buf = xfer.rx_buf = buf;
	buf[0] = OP_VDM_R;

	pr_debug("len = %d, xfer.len = %d, buf = %p, rx_buf = %p\n",
			ioc->len, xfer.len, buf, ioc->rx_buf);

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("read data error retval = %d\n", retval);
		goto end;
	}

	if (copy_to_user((u8 __user *) (uintptr_t) ioc->rx_buf, buf + 1,
			ioc->len)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
	}
end:
	kfree(buf);
	return retval;
#endif
}

int et5xx_io_vdm_write(struct et5xx_data *etspi, struct egis_ioc_transfer *ioc)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;
	u8 *buf = NULL;

	struct spi_transfer xfer = {
		.tx_buf = NULL,
		.rx_buf = NULL,
		.len = ioc->len + 1,
	};

	if (xfer.len >= LARGE_SPI_TRANSFER_BUFFER) {
		if ((xfer.len) % DIVISION_OF_IMAGE != 0)
			xfer.len = xfer.len + (DIVISION_OF_IMAGE -
					(xfer.len % DIVISION_OF_IMAGE));
	}

	buf = kzalloc(xfer.len, GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;

	if (copy_from_user((u8 __user *) (uintptr_t) buf + 1, ioc->tx_buf,
			ioc->len)) {
		pr_err("buffer copy_from_user fail retval\n");
		retval = -EFAULT;
		goto end;
	}

	xfer.tx_buf = xfer.rx_buf = buf;
	buf[0] = OP_VDM_W;

	pr_debug("len = %d, xfer.len = %d, buf = %p, tx_buf = %p\n",
			 ioc->len, xfer.len, buf, ioc->tx_buf);

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);

	if (retval < 0)
		pr_err("read data error retval = %d\n", retval);
end:
	kfree(buf);
	return retval;
#endif
}

int et5xx_io_get_frame(struct et5xx_data *etspi, u8 *fr, u32 size)
{
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	return 0;
#else
	int retval;
	struct spi_message m;
	u8 *buf = NULL;

	struct spi_transfer xfer = {
		.tx_buf = NULL,
		.rx_buf = NULL,
		.len = size + 1,
	};

	if (xfer.len >= LARGE_SPI_TRANSFER_BUFFER) {
		if ((xfer.len) % DIVISION_OF_IMAGE != 0)
			xfer.len = xfer.len + (DIVISION_OF_IMAGE -
					(xfer.len % DIVISION_OF_IMAGE));
	}

	buf = kzalloc(xfer.len, GFP_KERNEL);

	if (buf == NULL)
		return -ENOMEM;

	xfer.tx_buf = xfer.rx_buf = buf;
	buf[0] = OP_IMG_R;

	pr_debug("size = %d, xfer.len = %d, buf = %p, fr = %p\n",
		size, xfer.len, buf, fr);

	spi_message_init(&m);
	spi_message_add_tail(&xfer, &m);
	retval = spi_sync(etspi->spi, &m);
	if (retval < 0) {
		pr_err("read data error retval = %d\n", retval);
		goto end;
	}

	if (copy_to_user((u8 __user *) (uintptr_t) fr, buf + 1, size)) {
		pr_err("buffer copy_to_user fail retval\n");
		retval = -EFAULT;
	}
end:
	kfree(buf);
	return retval;
#endif
}