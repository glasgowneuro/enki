/*
    Enki - a fast 2D robot simulator
    Copyright (C) 1999-2006 Stephane Magnenat <stephane at magnenat dot net>
    Copyright (C) 2004-2005 Markus Waibel <markus dot waibel at epfl dot ch>
    Copyright (c) 2004-2005 Antoine Beyeler <antoine dot beyeler at epfl dot ch>
    Copyright (C) 2005-2006 Laboratory of Intelligent Systems, EPFL, Lausanne
    Copyright (C) 2006 Laboratory of Robotics Systems, EPFL, Lausanne
    See AUTHORS for details

    This program is free software; the authors of any publication 
    arising from research using this software are asked to add the 
    following reference:
    Enki - a fast 2D robot simulator
    http://lis.epfl.ch/enki
    Stephane Magnenat <stephane at magnenat dot net>,
    Markus Waibel <markus dot waibel at epfl dot ch>
    Laboratory of Intelligent Systems, EPFL, Lausanne.

    You can redistribute this program and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __ACTIVESOUNDOBJECT_H
#define __ACTIVESOUNDOBJECT_H

#include <enki/Interaction.h>
#include <enki/PhysicalEngine.h>

/*!	\file ActiveSoundSource.h
	\brief Header of sound emitter interaction
*/
namespace Enki
{
	
	//! Time limited sound emitter
	/*! \ingroup interaction */
	class ActiveSoundSource: public LocalInteraction
	{
	public:
		//! No of channels of this sound source
		unsigned noOfChannels;
		
		//! Produced sound: vector of different pitch as they were channels.
		double *pitch;
		
		//! Sound activity
		bool enableFlag;
		//! Elapsed time since last activation
		double elapsedTime;
		//! Activity time
		double activityTime;
		
		//! Constructor
		ActiveSoundSource(Robot *owner, double r, unsigned channels);
		//! Destructor
		~ActiveSoundSource();
		// Local interaction functions
		virtual void init() {}
		virtual void objectStep(double dt, PhysicalObject *po, World *w) {}
		
		void setSoundRange(double range);
		double getSound(unsigned channel);
		double getMaxSound(int* channel);
		void setSound(unsigned channel, double signal);
		void realisticSetSound(unsigned channel, double signal);
	};
	
	//! ActiveSoundObject can be inherited by any robot that want to emit sound
	/*! \ingroup robot */
	class ActiveSoundObject
	{
	public:
		//! Speaker
		ActiveSoundSource speaker;

	public:
		//! Constructor. Owner must point to the object which carries this emitter
		ActiveSoundObject(Robot *owner, double actionRange, unsigned channels);
	};
}

#endif
