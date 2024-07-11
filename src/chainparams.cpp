// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2020 The PIVX developers
// Copyright (c) 2021-2022 The DECENOMY Core Developers
// Copyright (c) 2023-2023 The EIGBankCoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.



/*
  ______ _____ _____   ____          _   _ _  __   _____ ____ _____ _   _ 
 |  ____|_   _/ ____| |  _ \   /\   | \ | | |/ /  / ____/ __ \_   _| \ | |
 | |__    | || |  __  | |_) | /  \  |  \| | ' /  | |   | |  | || | |  \| |
 |  __|   | || | |_ | |  _ < / /\ \ | . ` |  <   | |   | |  | || | | . ` |
 | |____ _| || |__| | | |_) / ____ \| |\  | . \  | |___| |__| || |_| |\  |
 |______|_____\_____| |____/_/    \_\_| \_|_|\_\  \_____\____/_____|_| \_|
                                                                          
*/


#include "chainparams.h"

#include "chainparamsseeds.h"
#include "consensus/merkle.h"
#include "util.h"
#include "utilstrencodings.h"

#include <boost/assign/list_of.hpp>

#include <assert.h>

#define DISABLED 0x7FFFFFFE;

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.nVersion = nVersion;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "EIGBankCoin";
    const CScript genesisOutputScript = CScript() << ParseHex("0496c26372a72b0ad40526e0a627aa4fb99d21cf987908c26e58b475e70719ccd4e64b25c109ec8e0b9eb59c457af356c65a0881538c8d46373d8fede9e313994b") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}



static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x000008402f0d330bc254bf7262327c79bdde7f621dea3e0b49ad4a7b199e397d")) // Genesis
    (1, uint256("0x00000f30d5112d919825a1d8be56722f9c772a1defcd3dbd3473d93893cbeab9"))
    (21, uint256("0x000007e236cf5f2696faf25b32471b1a3ae23c01cfc72a0ff137e11b5f24d627"))
    (38, uint256("0x0000080fd5130a51b14f4acf810af325a931b7d27031479a58f695ea75e4b0af"))
    (51, uint256("0x4822aa4c61bfa92ca06fa74e2a95c98b7fc30836d0f284ca4f77e3f4b365b9a8"))
    (73, uint256("0xcbe034d9db9943507bb151b244668f9bf2481db54ab7f27445db81602b620ab0"))
    (78, uint256("0x83e1a187e866427dd958f869aefc89340bc976215599f2e25b7ff8029444651e"))
    (83, uint256("0x4b240097233297ad3f41b2a5f81208c1b85ed7f125663ede617b86ecd83095d8"))
    (88, uint256("0x8ba846ffdd9717d18af6f5e86a75944fbeb31b0ad0983b764fafa04d93f5e103"))
    (251, uint256("0xd625ee0d501476c27b5463f248a0dc9c965cb7149226330923c42662566a96b4"))
    (1364, uint256("0xb1f66177b2a6a31aa96905c6314bc392d6abcc77b6e32a11492cdc9fd66062a9"))
    (89853, uint256("0x447960e2ed47b68cedaaa8e8b60af151e094fd22af7b68c1d904ee77b4eb8bd1"))
; 

static const Checkpoints::CCheckpointData data =
	{ &mapCheckpoints, 1690571130, 179660, 1.0000 };

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256S("0x0000037a6b770b4b8ed2f3009f2b4fa54d03cb0d6f3a09b85886d7554681b09b"));

static const Checkpoints::CCheckpointData dataTestnet =
	{ &mapCheckpoints, 1689093887, 0, 0 };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256S("0x0000002c4d21b82c611d9daf12e96620539823c722924d124d4f32f4fed7e49b"));

static const Checkpoints::CCheckpointData dataRegtest =
	{ &mapCheckpoints, 1689093889, 0, 0 };


/**
  __  __           _                          _   
 |  \/  |   __ _  (_)  _ __    _ __     ___  | |_ 
 | |\/| |  / _` | | | | '_ \  | '_ \   / _ \ | __|
 | |  | | | (_| | | | | | | | | | | | |  __/ | |_ 
 |_|  |_|  \__,_| |_| |_| |_| |_| |_|  \___|  \__|
                                                  
 */


class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";

        genesis = CreateGenesisBlock(1689093888, 1485694, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x000008402f0d330bc254bf7262327c79bdde7f621dea3e0b49ad4a7b199e397d"));
        assert(genesis.hashMerkleRoot == uint256S("0x42d4e28960d5508127c18cf8620a2f4594b48ae31ed560649289b40e7deadff9"));

        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.powLimit   = ~UINT256_ZERO >> 20;
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nCoinbaseMaturity = 20;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = 92600000 * COIN;
        consensus.nPoolMaxTransactions = 3;
        consensus.nStakeMinAge = 3 * 60;
        consensus.nStakeMinDepth = 5;
        consensus.nStakeMinDepthV2 = 30;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 0.25 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys
        consensus.strSporkPubKey = "037d54e99e93910258b1d4719e42c85df2cb270fbb1264dc108fb5a953afda0dfe";
        consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // burn addresses
        consensus.mBurnAddresses = {
           //{ "7XXXXXXXXXXXXXXXXXXXXXXXXXXXaqpZch", 0 }
        };

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                   = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight              = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                    = 51;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                 = 73;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                  = 73;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MODIFIER_V2].nActivationHeight      = 78;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_PROTOCOL_V2].nActivationHeight       = 83;
        consensus.vUpgrades[Consensus::UPGRADE_P2PKH_BLOCK_SIGNATURES].nActivationHeight = 88;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].nActivationHeight     = 251;
        consensus.vUpgrades[Consensus::UPGRADE_MASTERNODE_RANK_V2].nActivationHeight     = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;

        consensus.vUpgrades[Consensus::UPGRADE_POS].hashActivationBlock                    = uint256S("0x4822aa4c61bfa92ca06fa74e2a95c98b7fc30836d0f284ca4f77e3f4b365b9a8");
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].hashActivationBlock                 = uint256S("0xcbe034d9db9943507bb151b244668f9bf2481db54ab7f27445db81602b620ab0");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock                  = uint256S("0xcbe034d9db9943507bb151b244668f9bf2481db54ab7f27445db81602b620ab0");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MODIFIER_V2].hashActivationBlock      = uint256S("0x83e1a187e866427dd958f869aefc89340bc976215599f2e25b7ff8029444651e");
        consensus.vUpgrades[Consensus::UPGRADE_TIME_PROTOCOL_V2].hashActivationBlock       = uint256S("0x4b240097233297ad3f41b2a5f81208c1b85ed7f125663ede617b86ecd83095d8");
        consensus.vUpgrades[Consensus::UPGRADE_P2PKH_BLOCK_SIGNATURES].hashActivationBlock = uint256S("0x8ba846ffdd9717d18af6f5e86a75944fbeb31b0ad0983b764fafa04d93f5e103");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].hashActivationBlock     = uint256S("0xd625ee0d501476c27b5463f248a0dc9c965cb7149226330923c42662566a96b4");
        //consensus.vUpgrades[Consensus::UPGRADE_MASTERNODE_RANK_V2].hashActivationBlock     = uint256S("0x00");

        // Treasury
        consensus.nTreasuryActivationHeight = INT_MAX;
        consensus.nTreasuryPercentage = 0;
        consensus.strTreasuryAddress = "";

        pchMessageStart[0] = 0xa5;
        pchMessageStart[1] = 0xe6;
        pchMessageStart[2] = 0xc8;
        pchMessageStart[3] = 0xf9;
        nDefaultPort = __PORT_MAINNET__;

        vSeeds.push_back(CDNSSeedData("seeder1", "seed01.eigbankcoin.io"));
        vSeeds.push_back(CDNSSeedData("seeder2", "seed02.eigbankcoin.io"));
        vSeeds.push_back(CDNSSeedData("seeder3", "seed03.eigbankcoin.io"));
        vSeeds.push_back(CDNSSeedData("seeder4", "seed04.eigbankcoin.io"));
        vSeeds.push_back(CDNSSeedData("seeder5", "seed05.eigbankcoin.io"));
        vSeeds.push_back(CDNSSeedData("seeder6", "seed06.eigbankcoin.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 33);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 92);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 161);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x73).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x1d)(0xfc).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));
        //convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main)); // added
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }

};
static CMainParams mainParams;



/**
  _____                _                    _   
 |_   _|   ___   ___  | |_   _ __     ___  | |_ 
   | |    / _ \ / __| | __| | '_ \   / _ \ | __|
   | |   |  __/ \__ \ | |_  | | | | |  __/ | |_ 
   |_|    \___| |___/  \__| |_| |_|  \___|  \__|
                                                
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";

        genesis = CreateGenesisBlock(1689093887, 1410133, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x0000037a6b770b4b8ed2f3009f2b4fa54d03cb0d6f3a09b85886d7554681b09b"));
        assert(genesis.hashMerkleRoot == uint256S("0x42d4e28960d5508127c18cf8620a2f4594b48ae31ed560649289b40e7deadff9"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 12;   // EIGBankCoin starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nCoinbaseMaturity = 3;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = INT_MAX * COIN;
        consensus.nPoolMaxTransactions = 2;
        consensus.nStakeMinAge = 60 * 60;
        consensus.nStakeMinDepth = 100;
        consensus.nStakeMinDepthV2 = 200;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        // spork keys
        consensus.strSporkPubKey = "03c864ae61dd691747091314b310a702c637511274ed0d65397f8c0ae0e2e7fd7c";
        consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                      = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight                 = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                       = 51;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                    = 101;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                     = 101;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MODIFIER_V2].nActivationHeight         = 201;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_PROTOCOL_V2].nActivationHeight          = 301;
        consensus.vUpgrades[Consensus::UPGRADE_P2PKH_BLOCK_SIGNATURES].nActivationHeight    = 401;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].nActivationHeight        = 501;

        consensus.vUpgrades[Consensus::UPGRADE_POS].hashActivationBlock                     = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].hashActivationBlock                  = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].hashActivationBlock                   = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MODIFIER_V2].hashActivationBlock       = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_TIME_PROTOCOL_V2].hashActivationBlock        = uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_P2PKH_BLOCK_SIGNATURES].hashActivationBlock  =uint256S("0x0");
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MIN_DEPTH_V2].hashActivationBlock      = uint256S("0x0");

        // Treasury
        consensus.nTreasuryActivationHeight = INT_MAX;
        consensus.nTreasuryPercentage = 0;
        consensus.strTreasuryAddress = "";


        pchMessageStart[0] = 0xa4;
        pchMessageStart[1] = 0xa4;
        pchMessageStart[2] = 0xa4;
        pchMessageStart[3] = 0xa4;
        nDefaultPort = __PORT_TESTNET__;

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        //vSeeds.push_back(CDNSSeedData("tseeder", "xxxxxxx", true));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 128);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 194);
        // Testnet EIGBankCoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet EIGBankCoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet EIGBankCoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;



/**
  ____                   _                  _   
 |  _ \    ___    __ _  | |_    ___   ___  | |_ 
 | |_) |  / _ \  / _` | | __|  / _ \ / __| | __|
 |  _ <  |  __/ | (_| | | |_  |  __/ \__ \ | |_ 
 |_| \_\  \___|  \__, |  \__|  \___| |___/  \__|
                 |___/                          
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";

        genesis = CreateGenesisBlock(1689093889, 3120125, 0x1e0ffff0, 1, 0 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256S("0x0000002c4d21b82c611d9daf12e96620539823c722924d124d4f32f4fed7e49b"));
        assert(genesis.hashMerkleRoot == uint256S("0x42d4e28960d5508127c18cf8620a2f4594b48ae31ed560649289b40e7deadff9"));

        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.powLimit   = ~UINT256_ZERO >> 12;   // EIGBankCoin starting difficulty is 1 / 2^12
        consensus.posLimitV1 = ~UINT256_ZERO >> 24;
        consensus.posLimitV2 = ~UINT256_ZERO >> 20;
        consensus.nCoinbaseMaturity = 3;
        consensus.nFutureTimeDriftPoW = 7200;
        consensus.nFutureTimeDriftPoS = 180;
        consensus.nMaxMoneyOut = 250 * COIN;
        consensus.nPoolMaxTransactions = 2;
        consensus.nStakeMinAge = 0;
        consensus.nStakeMinDepth = 2;
        consensus.nTargetTimespan = 40 * 60;
        consensus.nTargetTimespanV2 = 30 * 60;
        consensus.nTargetSpacing = 1 * 60;
        consensus.nTimeSlotLength = 15;

        consensus.strSporkPubKey = "0226603c8331ba9e829e2dcfec6d08b87a52d85f03416b5969c0b7e17901b9035c";
        consensus.strSporkPubKeyOld = "";
        consensus.nTime_EnforceNewSporkKey = 0;
        consensus.nTime_RejectOldSporkKey = 0;

        // Network upgrades
        consensus.vUpgrades[Consensus::BASE_NETWORK].nActivationHeight                    = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_TESTDUMMY].nActivationHeight               = Consensus::NetworkUpgrade::NO_ACTIVATION_HEIGHT;
        consensus.vUpgrades[Consensus::UPGRADE_POS].nActivationHeight                     = 251;
        consensus.vUpgrades[Consensus::UPGRADE_POS_V2].nActivationHeight                  = 251;
        consensus.vUpgrades[Consensus::UPGRADE_BIP65].nActivationHeight                   = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_STAKE_MODIFIER_V2].nActivationHeight       = 251;
        consensus.vUpgrades[Consensus::UPGRADE_TIME_PROTOCOL_V2].nActivationHeight        = Consensus::NetworkUpgrade::ALWAYS_ACTIVE;
        consensus.vUpgrades[Consensus::UPGRADE_P2PKH_BLOCK_SIGNATURES].nActivationHeight  = 300;

        // Treasury
        consensus.nTreasuryActivationHeight = INT_MAX;
        consensus.nTreasuryPercentage = 0;
        consensus.strTreasuryAddress = "";


        pchMessageStart[0] = 0xf1;
        pchMessageStart[1] = 0xf1;
        pchMessageStart[2] = 0xf1;
        pchMessageStart[3] = 0xf1;
        nDefaultPort = __PORT_REGTEST__;

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }

    void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
    {
        assert(idx > Consensus::BASE_NETWORK && idx < Consensus::MAX_NETWORK_UPGRADES);
        consensus.vUpgrades[idx].nActivationHeight = nActivationHeight;
    }
};
static CRegTestParams regTestParams;

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

void UpdateNetworkUpgradeParameters(Consensus::UpgradeIndex idx, int nActivationHeight)
{
    regTestParams.UpdateNetworkUpgradeParameters(idx, nActivationHeight);
}
