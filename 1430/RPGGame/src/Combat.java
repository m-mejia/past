
public class Combat {
    public Combat() {
    }

    public void initCombat(Player player, Monster monster) {
        System.out.println(player.getName() + " HP: " + player.getHP() + " | " +  monster.getName() + " HP: " + monster.getHP());
        while (true) {
            attackSequence(player, monster);
            attackSequence(monster, player);
        }
    }

    private void attackSequence(Actor attacker, Actor defender) {
        int attackerDamage = getDamage(attacker);
        defender.setHP(defender.getHP() - attackerDamage);
        combatResult(attacker, attackerDamage);
        System.out.println(defender.getName() + " HP: " + defender.getHP());
        checkDefeat(defender);
    }

    private void checkDefeat(Actor actor) {
        if(actor.getHP() < 1) {
            System.out.println("\nCombat is over!");
            System.out.println(actor.getName() + " is defeated!\n");
            System.exit(0);
        }
    }

    private int getDamage(Actor actor) {
        return actor.generateRandomAttack();
    }

    private void combatResult(Actor actor, int damage) {
        System.out.println(actor.getName() + " attacks with " + damage);
    }
}
