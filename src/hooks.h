#pragma once
class hitEventHook //props to Loki
{
public:
    static void InstallHook() {
        REL::Relocation<uintptr_t> hook{ REL::RelocationID(37673, 38627) };
        SKSE::AllocTrampoline(1 << 4);
        auto& trampoline = SKSE::GetTrampoline();
        _ProcessHit = trampoline.write_call<5>(hook.address() + REL::Relocate(0x3C0, 0x4A8), processHit);
        logger::info("hit event hook installed!");
    };
private:
    static void processHit(RE::Actor* target, RE::HitData& hitData);
    static inline REL::Relocation<decltype(processHit)> _ProcessHit;
};

class staminaRegenHook //props to Ersh
{
public:
    static void InstallHook() {
        REL::Relocation<uintptr_t> hook{ REL::RelocationID(37510, 38452) };  // 620690 - a function that regenerates stamina
        SKSE::AllocTrampoline(1 << 4);
        auto& trampoline = SKSE::GetTrampoline();
        _shouldRegenStamina = trampoline.write_call<5>(hook.address() + REL::Relocate(0x62, 0x6F), shouldRegenStamina);
        logger::info("stamina regen hook installed");
    };
private:
    static bool shouldRegenStamina(RE::ActorState* a_this, uint16_t a_flags);
    static inline REL::Relocation<decltype(shouldRegenStamina)> _shouldRegenStamina;
};