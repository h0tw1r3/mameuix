// license:BSD-3-Clause
// copyright-holders:Aaron Giles
#ifndef MAME_SOUND_BBD_H
#define MAME_SOUND_BBD_H

#pragma once

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> bbd_device_base

template<int Entries, int Outputs>
class bbd_device_base : public device_t, public device_sound_interface
{
protected:
	// internal constructor
	bbd_device_base(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock, device_type type);

	// override to convert clock to sample rate
	virtual u32 sample_rate() const { return clock(); }

	// device-level overrides
	virtual void device_start() override;
	virtual void device_clock_changed() override;

	// sound stream update overrides
	virtual void sound_stream_update(sound_stream &stream, std::vector<read_stream_view> const &inputs, std::vector<write_stream_view> &outputs) override;

protected:
	sound_stream *          m_stream;
	u32                     m_curpos;
	stream_buffer::sample_t m_buffer[Entries];
};


// ======================> mn3004_device

class mn3004_device : public bbd_device_base<512, 2>
{
public:
	mn3004_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 0);
};

DECLARE_DEVICE_TYPE(MN3004, mn3004_device)


// ======================> mn3005_device

class mn3005_device : public bbd_device_base<4096, 2>
{
public:
	mn3005_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 0);
};

DECLARE_DEVICE_TYPE(MN3005, mn3005_device)


// ======================> mn3006_device

class mn3006_device : public bbd_device_base<128, 2>
{
public:
	mn3006_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 0);
};

DECLARE_DEVICE_TYPE(MN3006, mn3006_device)


// ======================> mn3204p_device

class mn3204p_device : public bbd_device_base<512, 2>
{
public:
	mn3204p_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 0);
};

DECLARE_DEVICE_TYPE(MN3204P, mn3204p_device)

#endif // MAME_SOUND_BBD_H