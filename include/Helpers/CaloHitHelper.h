/**
 *  @file   PandoraPFANew/Framework/include/Helpers/CaloHitHelper.h
 * 
 *  @brief  Header file for the calo hit helper class.
 * 
 *  $Log: $
 */
#ifndef PANDORA_CALO_HIT_HELPER_H
#define PANDORA_CALO_HIT_HELPER_H 1

#include "Pandora/PandoraInternal.h"
#include "Pandora/StatusCodes.h"

namespace pandora
{

class TiXmlHandle;

//------------------------------------------------------------------------------------------------------------------------------------------

/**
 *  @brief  CaloHitHelper class
 */
class CaloHitHelper
{
public:
    /**
     *  @brief  Count number of "nearby" hits using the isolation scheme
     * 
     *  @param  pCaloHit the calo hit
     *  @param  pCaloHitList the calo hit list
     * 
     *  @return the number of nearby hits
     */
    static unsigned int IsolationCountNearbyHits(const CaloHit *const pCaloHit, const CaloHitList *const pCaloHitList);

    /**
     *  @brief  Count number of "nearby" hits using the mip identification scheme
     * 
     *  @param  pCaloHit the calo hit
     *  @param  pCaloHitList the calo hit list
     * 
     *  @return the number of nearby hits
     */
    static unsigned int MipCountNearbyHits(const CaloHit *const pCaloHit, const CaloHitList *const pCaloHitList);

private:
    /**
     *  @brief  Calculate calo hit properties for a particular calo hit, through comparison with an ordered list of other hits.
     *          Calculates density weights, isolation flags, possible mip flags and surrounding energy
     * 
     *  @param  pCaloHit the calo hit
     *  @param  pOrderedCaloHitList the ordered calo hit list
     */
    static void CalculateCaloHitProperties(CaloHit *const pCaloHit, const OrderedCaloHitList *const pOrderedCaloHitList);

    /**
     *  @brief  Read the calo hit helper settings
     * 
     *  @param  pXmlHandle address of the relevant xml handle
     */
    static StatusCode ReadSettings(const TiXmlHandle *const pXmlHandle);

    static float                    m_caloHitMaxSeparation2;            ///< Max separation to consider associations between hits, units mm (used squared)
    static float                    m_isolationCaloHitMaxSeparation2;   ///< Max separation considered when identifying isolated hits, units mm (used squared)

    static unsigned int             m_isolationNLayers;                 ///< Number of adjacent layers to use in isolation calculation
    static float                    m_isolationCutDistanceFine2;        ///< Fine granularity isolation cut distance, units mm (used squared)
    static float                    m_isolationCutDistanceCoarse2;      ///< Coarse granularity isolation cut distance, units mm (used squared)
    static unsigned int             m_isolationMaxNearbyHits;           ///< Max number of "nearby" hits for a hit to be considered isolated

    static float                    m_mipLikeMipCut;                    ///< Mip equivalent energy cut for hit to be flagged as possible mip
    static unsigned int             m_mipNCellsForNearbyHit;            ///< Separation (in calo cells) for hits to be declared "nearby"
    static unsigned int             m_mipMaxNearbyHits;                 ///< Max number of "nearby" hits for hit to be flagged as possible mip

    friend class CaloHitManager;
    friend class PandoraApiImpl;
    friend class PandoraContentApiImpl;
    friend class PandoraSettings;
};

} // namespace pandora

#endif // #ifndef PANDORA_CALO_HIT_HELPER_H
