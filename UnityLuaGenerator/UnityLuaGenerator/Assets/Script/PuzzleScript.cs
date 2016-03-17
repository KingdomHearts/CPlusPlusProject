using UnityEngine;
using System.Collections;

public class PuzzleScript : MonoBehaviour {

    [SerializeField]
    private Vector3 _finalPosition;

    public Vector3 FinalPosition { get { return _finalPosition; } set { _finalPosition = value; } }

    [SerializeField]
    private Vector3 _finalRotation;

    public Vector3 FinalRotation { get { return _finalRotation; } set { _finalRotation = value; } }

    [SerializeField]
    private Vector3 _finalScale;

	public Vector3 FinalScale { get { return _finalScale; } set { _finalScale = value; } }

	[SerializeField]
	private bool _isPainting;

	public bool IsPainting { get { return _isPainting; } set { _isPainting = value; } }
}
