import React, { Component } from 'react'
import { Text, View } from 'react-native'

import styles from '../static'
import LinodeApi from '../client'
import storage, { getToken, getPromo } from '../storage'
import { Capabilities, Promotions, RefreshButton } from '../components'

function BasicAccount(props) {
  let account = props.parent.state.account
  return (
    <View style={styles.sub}>
      <Text style={styles.text}>User: {account.first_name} {account.last_name} &lt;{account.email}&gt;</Text>
      <Text style={styles.text}>Balance: {account.balance}$</Text>
      <Text style={styles.text}>Uninvoiced balance: {account.balance_uninvoiced}$</Text>
    </View>
  )
}

export default class HomeScreen extends Component {
  constructor(props) {
    super(props)
    this.state = {
      account: {},
      hasPromotion: null,
      token: null
    }
    getPromo(this)
    //getToken(this)
    this.api = new LinodeApi()
    this.api.setToken()
  }
  componentDidMount() {
    setTimeout(() => { this.refresh(this) }, 50)
  }

  async refresh(that) {
    //let account
    /*
    that.setState({
      account: {
        balance_uninvoiced: '0.00'
      }
    })
    */
    let account = await that.api.getAccount()
    that.setState({'account': account})
    /*
    if (that.api.headers.Authorization != `Bearer ${that.state.token}`)
      that.api.setToken(that.state.token)
    if (that.state.token.length == 64) {
      account = await this.api.get('/account')
      that.setState({'account': account})
    }
    */
    /*
    if (!this.hasPromotion) {
      if (that.state.account.active_promotions.length > 0) {
        storage.save({
          key: 'hasPromo',
          data: true
        })
      } else {
        storage.save({
          key: 'hasPromo',
          data: false
        })
      }
    }
    */
  }

  render() {
    let token_state, basic_info, active_promotions = null
    if (typeof this.state.account.balance != 'undefined') {
      basic_info = <BasicAccount parent={this} />
    } else {basic_info = null}
    if (this.state.hasPromotion) {
      active_promotions = <Promotions parent={this} />
    } else { active_promotions = null }
    if (this.api.tokenState !== null) {
      token_state = <Text style={styles.error}>Invalid API token!</Text>
    }
    return (
      <View style={styles.container}>
        <Text style={styles.heading}>Linode Account Overview</Text>
        {token_state}
        {basic_info}
        <Text style={styles.heading2}>Capabilities</Text>
        <Capabilities parent={this} />
        <Text style={styles.heading2}>Active Promotions</Text>
        {active_promotions}
        <RefreshButton parent={this} />
        <Text style={styles.heading2}>{this.api.headers.Authorization}</Text>
      </View>
    )
  }
}
