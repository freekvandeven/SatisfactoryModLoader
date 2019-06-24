#pragma once
#include <../SatisfactorySDK/SDK.hpp>
#include <Lib.h>

namespace SML {
	namespace Assets {
		/**
		* Current UWorld object.
		*/
		SML_API extern void* CurrentWorld;

		/**
		* Single player character
		*/
		SML_API extern SDK::AFGCharacterPlayer* SinglePlayerCharacter;

		/**
		* Single player controller
		*/
		SML_API extern SDK::AFGPlayerController* SinglePlayerController;
	}
	namespace Mod {
		namespace Functions {
			/**
			* This function has been largely replaced by the asset caching system. To prevent slowdowns, use that instead!
			* 
			* Load an object from a pak file. Will crash if the pak is not installed.
			*
			* The asset name must be of the following format: \\Game\\FactoryGame\\Path\\To\\Asset\\AssetFile.AssetFile
			* If you are loading a blueprint, the name must have a _C appended to the end.
			*/
			SML_API SDK::UObject* loadObjectFromPak(SDK::UClass *ObjectClass, const wchar_t *InName);

			/**
			* Spawns an actor at a given location, when given the world.
			*/
			SML_API void* spawnActor(void* UWorld, void* *UClass, void* *FVector, void* *FRotator, void* *FActorSpawnParameters);

			/**
			* Get the current global world object.
			*/
			SML_API void* getWorld();

			/**
			* Get the local player character
			*/
			SML_API SDK::AFGCharacterPlayer* getPlayerCharacter();

			/**
			* Get the local player controller
			*/
			SML_API SDK::AFGPlayerController* getPlayerController();

			/**
			* Spawn an actor at the player, offset by the XYZ values provided.
			*/
			SML_API void spawnActorAtPlayer(SDK::UObject* obj, float x, float y, float z);

			/**
			* Spawn an actor at the player.
			*/
			SML_API void spawnActorAtPlayer(SDK::UObject* obj);

			/**
			* Spawn an actor at the provided location with the provided rotation.
			*/
			SML_API void spawnActor(SDK::UObject* obj, float x, float y, float z, float pitch, float roll, float yaw);

			/**
			* Adds a UFGRecipe to the game.
			* Code kindly provided by Trxnce.
			*/
			SML_API void addRecipe(SDK::UClass* recipe);

			/**
			* Returns an ItemStack from an item class and an item amount.
			* Code kindly provided by Trxnce.
			*/
			SML_API SDK::FInventoryStack makeItemStack(SDK::UClass* clazz, const int& amount);

			/**
			* Adds an item with an amount to the player's inventory.
			* Code kindly provided by Trxnce.
			*/
			SML_API void addItemStackToPlayer(SDK::UObject* item, const int& amount);

			/**
			* Adds a stack to the player's inventory.
			*/
			SML_API void addItemStackToPlayer(SDK::FInventoryStack stack);

			/**
			* Sends a chat message to the local player controller.
			*/
			SML_API void sendMessageToPlayer(std::string msg);

			/**
			* Registers an asset path for caching.
			*
			* This removes delays and sutters when loading an asset during gameplay.
			* Only call this during setup and post setup! calling it afterwards will just cache the object at the time it's called.
			*
			* This function returns an int id for ease of access when getting an item back from the cache.
			*/
			SML_API int registerAssetForCache(const wchar_t* name);

			/**
			* Returns the UObject pointer from the cache for spawning.
			*
			* Will crash if called before satisfactory is running or if the name isn't found in the cache!
			*/
			SML_API SDK::UObject* getAssetFromCache(const wchar_t* name);

			/**
			* Gets an item back from the cache with the specified id.
			* Will crash if the id isn't found.
			*/
			SML_API SDK::UObject* getAssetFromCacheWithID(int id);

			/**
			*  Get's an asset's name back from the cache with the name's id.
			* Will crash if the id isn't found.
			*/
			SML_API const wchar_t* getAssetNameFromID(int id);
		}
	}
}