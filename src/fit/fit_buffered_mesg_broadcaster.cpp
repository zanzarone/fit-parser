/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2023 Garmin International, Inc.
// Licensed under the Flexible and Interoperable Data Transfer (FIT) Protocol License; you
// may not use this file except in compliance with the Flexible and Interoperable Data
// Transfer (FIT) Protocol License.
/////////////////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 21.126.0Release
// Tag = production/release/21.126.0-0-g0576dfe
/////////////////////////////////////////////////////////////////////////////////////////////



#include "fit_buffered_mesg_broadcaster.hpp"


namespace fit
{

void BufferedMesgBroadcaster::RegisterMesgBroadcastPlugin(MesgBroadcastPlugin* plugin)
{
   plugins.push_back(plugin);
}

void BufferedMesgBroadcaster::OnMesg(Mesg& mesg)
{
   mesgs.push_back(mesg);

   // Pass the message to each plugin. This gives the
   // plugin a chance to peek the incoming messages
   for(size_t i = 0; i < plugins.size(); i++)
   {
      if(plugins[i])
         plugins[i]->OnIncomingMesg(mesg);
   }
}

void BufferedMesgBroadcaster::Broadcast(void)
{
   for(size_t i = 0; i < plugins.size(); i++)
   {
      if(plugins[i])
         plugins[i]->OnBroadcast(mesgs);
   }

   for(size_t j = 0; j < mesgs.size(); j++)
   {
      MesgBroadcaster::OnMesg(mesgs[j]);
   }
}

} // namespace fit
