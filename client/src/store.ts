import { AnyAction, createStore, Reducer } from "redux";

export interface Player {
    connected: boolean;
    name: string;
    score: number;
    win_count: number;
}

export interface DieRoll {
    used: boolean;
    value: number;
}
export interface ReduxState {
    players: Player[];
    rolls: DieRoll[];
    rolled: false;
    turn_index: number;
    self_index: number;
    game_over: boolean;
    socket?: WebSocket;
}

const initialState: ReduxState = {
    players: [],
    rolls: [],
    rolled: false,
    turn_index: 0,
    self_index: 0,
    game_over: false,
}

const rootReducer: Reducer<ReduxState> = (state: ReduxState = initialState, action: AnyAction) => {
    switch (action.type) {
        case "WEBSOCKET":
            return {
                ...state,
                socket: action.socket
            }
        case "welcome":
            console.log(action);
            const { game } = action;
            const rolls = [];
            for (let i = 0; i < game.rolls.length; ++i) {
                rolls.push({ used: game.used[i], value: game.rolls[i] })
            }
            return Object.assign({}, state, initialState, game, { players: game.players }, { self_index: action.id }, { rolls })
        case "join":
            return {
                ...state,
                players: state.players.concat({ connected: true, name: "Loading...", score: 0, win_count: 0 })
            }

        case "disconnect":
        case "reconnect":
            return {
                ...state,
                players: state.players.map((p: Player, i: number) => (i !== action.id) ? { ...p, connected: action.type === "reconnect" } : p),
            }
        case "update":
            return {
                ...state,
                players: state.players.map((p: Player, i: number) => (i !== action.id) ? { ...p, score: action.score } : p),
                rolls: "used" in action ? action.used.map((used: boolean, i: number) => ({ used, value: state.rolls[i].value })) : state.rolls,
            }
        case "update_turn":
            return {
                ...state,
                turn_index: action.id,
                rolled: false,
            }
            case "roll_again":
            return {
                ...state,
                rolled: false,
            }
        case "leave":
        case "kick":
            return {
                ...state,
                players: [...state.players.slice(0, action.id), ...state.players.slice(action.id + 1)]
            }
        case "roll":
            return {
                ...state,
                rolls: action.rolls.map((roll: number) => ({ value: roll, used: false })),
                rolled: true,
            }
        default:
            console.error("RECEIVED UNKNOWN ACTION", action);
    }
    return state;
};

export const selectState = (state: ReduxState) => state;

export const store = createStore(rootReducer);
