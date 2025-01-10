using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UIController : MonoBehaviour {

	public Text unitNameText;
    public Text healthPoints;
    public Text goldAmount;
    public Text damageDone;
    public Text unitLevel;
    public Text specialUsed;
    public GameObject xpBar;
	public GameObject unitControlPanel;

	public void SetUnitInfo(Unit unit) {
		if (unit == null) {
			HideUnitPanel();
			return;
		}

        if (unit.totalDamage == 0)
            damageDone.text = "Damage Done: ";

        else if (unit.totalDamage > 0)
            damageDone.text = "Damage done: " + unit.totalDamage.ToString();
        else
            damageDone.text = "Damage done: Miss";

        specialUsed.text = "Special: " + unit.special.ToString();
        unitLevel.text = "Level " + unit.unitLevel.ToString();
        unitNameText.text = unit.unitName;
        healthPoints.text = "HP: " + unit.hp.ToString() + "/100";
        goldAmount.text = "Current Gold:  " + unit.gold.ToString();
        xpBar.transform.localScale = new Vector3(unit.xp, 1f, 1f);
		ShowUnitPanel ();
	}

	public void ShowUnitPanel() {
		unitControlPanel.SetActive (true);
	}

	public void HideUnitPanel() {
		unitControlPanel.SetActive (false);
	}
}
